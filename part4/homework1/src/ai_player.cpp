#include "ai_player.h"
#include <string>

AIPlayer::AIPlayer(std::string inName) : Player(inName) {}

unsigned AIPlayer::getMove(unsigned min, unsigned max, unsigned remainder) {
  return std::rand() % (max - min + 1) + min;
}