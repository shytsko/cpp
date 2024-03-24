#include "elf.h"
#include "branch.h"
#include <cassert>
#include <string>

Elf::Elf(std::string inName, Branch *inHomeBranch) {
  name = inName;
  homeBranch = inHomeBranch;
}

std::string Elf::getName(void) {
  assert(this != nullptr);
  return name;
}

Branch *Elf::getHomeBranch(void) {
  assert(this != nullptr);
  return homeBranch;
}

// Подсче соседей
int Elf::countNeighbors(void) {
  // Определяем основную ветку и считаем, сколько эльфов живет на основной ветке
  // и на всех дочерних
  Branch *mainBranch = homeBranch->getNumberChildBranches() == 0
                           ? homeBranch->getParentBranch()
                           : homeBranch;

  int count = mainBranch->getElf() != nullptr ? 1 : 0;

  for (int i = 0; i < mainBranch->getNumberChildBranches(); i++)
    if (mainBranch->getChildBranchAt(i)->getElf() != nullptr)
      count++;

  // От резульата отнимает 1 - самого эльфа, для которого считаем соседей
  return count - 1;
}