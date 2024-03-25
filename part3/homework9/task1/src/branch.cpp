#include "branch.h"
#include "elf.h"
#include <cassert>
#include <string>

Branch::Branch(Branch *inParentBranch) { parentBranch = inParentBranch; }

Branch *Branch::getParentBranch(void) { return parentBranch; }

void Branch::addChildBranches(int inNumberChildBranches) {
  assert(inNumberChildBranches > 0);

  numberChildBranches = inNumberChildBranches;
  childBranches = new Branch *[numberChildBranches];

  for (int i = 0; i < numberChildBranches; i++)
    childBranches[i] = new Branch(this);
}

int Branch::getNumberChildBranches(void) { return numberChildBranches; }

Branch *Branch::getChildBranchAt(int number) {
  assert(number >= 0);
  assert(number < numberChildBranches);
  return childBranches[number];
}

void Branch::addElf(std::string name) { elf = new Elf(name, this); }

Elf *Branch::getElf(void) { return elf; }

Elf *Branch::findElf(std::string name) {
  // Если на ветке живет эльф с искомым именем, возвращается ссылка на него
  if (elf != nullptr && elf->getName() == name)
    return elf;

  // Иначе поиск продолжается по дочерним веткам
  for (int i = 0; i < numberChildBranches; i++) {
    Elf *findedElf = childBranches[i]->findElf(name);
    if (findedElf != nullptr)
      return findedElf;
  }

  return nullptr;
}

Branch::~Branch() {
  for (int i = 0; i < numberChildBranches; i++)
    delete childBranches[i];

  delete[] childBranches;
  delete elf;
}