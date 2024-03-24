#include "forest.h"
#include "branch.h"
#include "elf.h"
#include <cstdlib>
#include <iostream>
#include <sstream>

int randBetween(int minValue, int maxValue) {
  return std::rand() % (maxValue - minValue + 1) + minValue;
}

std::string Forest::adressDecode(int tree, int mainBranch, int middleBranch) {
  std::stringstream ss;

  ss << "tree: " << tree << ", main branch: " << mainBranch;
  if (middleBranch)
    ss << ", middle branch: " << middleBranch;

  return ss.str();
}

std::string Forest::getElfAutoName(void) {
  static int counter = 0;

  int random = std::rand() % 100;
  if (random < 30)
    return "None";

  return "Elf" + std::to_string(++counter);
}

Forest::Forest(void) {
  trees = new Branch *[NUMBER_TREES];

  for (int i = 0; i < NUMBER_TREES; i++) {
    trees[i] = new Branch(nullptr);

    trees[i]->addChildBranches(
        randBetween(MIN_NUMBER_MAIN_BRANCHES, MAX_NUMBER_MAIN_BRANCHES));

    for (int j = 0; j < trees[i]->getNumberChildBranches(); j++)
      trees[i]->getChildBranchAt(j)->addChildBranches(
          randBetween(MIN_NUMBER_MIDDLE_BRANCHES, MAX_NUMBER_MIDDLE_BRANCHES));
  }
}

Forest::~Forest(void) {
  for (int i = 0; i < NUMBER_TREES; i++)
    delete trees[i];

  delete[] trees;
}

void Forest::settleElves(bool autoGenerate = false) {
  std::string name;
  for (int i = 0; i < NUMBER_TREES; i++) {
    for (int j = 0; j < trees[i]->getNumberChildBranches(); j++) {
      Branch *mainBranch = trees[i]->getChildBranchAt(j);
      std::cout << "Who will live here (" << adressDecode(i + 1, j + 1, 0)
                << ")? > ";

      if (autoGenerate) {
        name = getElfAutoName();
        std::cout << name << std::endl;
      } else {
        std::cin >> name;
      }
      if (name != "None")
        mainBranch->addElf(name);

      for (int k = 0; k < mainBranch->getNumberChildBranches(); k++) {
        Branch *middleBranch = mainBranch->getChildBranchAt(k);
        std::cout << "Who will live here (" << adressDecode(i + 1, j + 1, k + 1)
                  << ")? > ";
        if (autoGenerate) {
          name = getElfAutoName();
          std::cout << name << std::endl;
        } else {
          std::cin >> name;
        }
        if (name != "None")
          middleBranch->addElf(name);
      }
    }
  }
}

void Forest::view(void) {
  for (int i = 0; i < NUMBER_TREES; i++) {
    std::cout << "Tree " << i + 1 << "(" << trees[i] << ")" << std::endl;
    for (int j = 0; j < trees[i]->getNumberChildBranches(); j++) {
      Branch *mainBranch = trees[i]->getChildBranchAt(j);
      std::cout << "|-Main branch " << j + 1 << " (" << mainBranch << ")"
                << " -> ";
      if (mainBranch->getElf() != nullptr)
        std::cout << mainBranch->getElf()->getName() << std::endl;
      else
        std::cout << "(None)" << std::endl;

      for (int k = 0; k < mainBranch->getNumberChildBranches(); k++) {
        Branch *middleBranch = mainBranch->getChildBranchAt(k);

        std::cout << "  |-Middle branch " << k + 1 << " (" << middleBranch
                  << ")"
                  << " -> ";
        if (middleBranch->getElf() != nullptr)
          std::cout << middleBranch->getElf()->getName() << std::endl;
        else
          std::cout << "(None)" << std::endl;
      }
    }
  }
}

Elf *Forest::findElf(std::string name) {
  Elf *elf = nullptr;
  for (int i = 0; i < NUMBER_TREES; i++) {
    elf = trees[i]->findElf(name);
    if (elf != nullptr)
      break;
  }

  return elf;
}