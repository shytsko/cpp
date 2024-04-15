#ifndef H_AI_PLAYER
#define H_AI_PLAYER

#include "player.h"
#include <string>

class AIPlayer : public Player {
public:
  AIPlayer(std::string inName);
  virtual unsigned getMove(unsigned min, unsigned max,
                           unsigned remainder) override;
};

#endif