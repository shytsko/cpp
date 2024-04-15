#ifndef H_HUMAN_PLAYER
#define H_HUMAN_PLAYER

#include "player.h"
#include <string>

class HumanPlayer : public Player {
public:
  HumanPlayer(std::string inName);
  virtual unsigned getMove(unsigned min, unsigned max,
                           unsigned remainder) override;
};

#endif