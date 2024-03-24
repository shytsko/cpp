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

int Elf::countNeighbors(void) {
  Branch *mainBranch = homeBranch->getNumberChildBranches() == 0
                           ? homeBranch->getParentBranch()
                           : homeBranch;

  int count = mainBranch->getElf() != nullptr ? 1 : 0;

  for (int i = 0; i < mainBranch->getNumberChildBranches(); i++)
    if (mainBranch->getChildBranchAt(i)->getElf() != nullptr)
      count++;

  return count - 1;
}