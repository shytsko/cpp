#ifndef H_BRANCH
#define H_BRANCH

#include "elf.h"
#include <string>

class Branch {
  Branch *parentBranch = nullptr;
  Branch **childBranches = nullptr;
  int numberChildBranches = 0;
  Elf *elf = nullptr;

public:
  Branch(Branch *parentBranch);
  Branch *getParentBranch(void);
  void addChildBranches(int numberChildBranches);
  int getNumberChildBranches(void);
  Branch *getChildBranchAt(int number);
  void addElf(std::string name);
  Elf *getElf(void);
  Elf *findElf(std::string name);
  ~Branch();
};

#endif