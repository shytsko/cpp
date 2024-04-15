#ifndef H_HUMAN_PLAYER
#define H_HUMAN_PLAYER

#include "player.h"
#include <string>

// Игрок человек. Ввод очередного хода будет с клавиатуры
class HumanPlayer : public Player {
public:
  HumanPlayer(std::string inName);
  virtual unsigned getMove(unsigned min, unsigned max,
                           unsigned remainder) override;
};

#endif