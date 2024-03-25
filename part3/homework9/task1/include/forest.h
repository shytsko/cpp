#ifndef H_FOREST
#define H_FOREST

#include "branch.h"

#define NUMBER_TREES 5
#define MIN_NUMBER_MAIN_BRANCHES 3
#define MAX_NUMBER_MAIN_BRANCHES 5
#define MIN_NUMBER_MIDDLE_BRANCHES 2
#define MAX_NUMBER_MIDDLE_BRANCHES 3

class Forest {
  Branch **trees;

  static std::string adressDecode(int tree, int mainBranch, int middleBranch);
  static std::string getElfAutoName(void);

public:
  Forest(void);
  ~Forest(void);

  void settleElves(bool autoGenerate);
  void view(void);
  Elf *findElf(std::string);
};

#endif