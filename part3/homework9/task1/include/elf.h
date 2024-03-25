#ifndef H_ELF
#define H_ELF

#include <string>

class Branch;

class Elf {
  std::string name = "unknown";
  Branch *homeBranch = nullptr;

public:
  Elf(std::string name, Branch *homeBranch);
  std::string getName(void);
  int countNeighbors(void);
  Branch *getHomeBranch(void);
};

#endif