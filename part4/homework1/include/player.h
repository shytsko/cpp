#ifndef H_PLAYER
#define H_PLAYER

#include <string>

// Абстрактный класс игрока
class Player {
  std::string name;

protected:
  Player(std::string inName);

public:
  std::string getName(void);
  virtual unsigned getMove(unsigned min, unsigned max, unsigned remainder) = 0;
};

#endif