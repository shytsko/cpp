#include "ai_player.h"
#include <string>

AIPlayer::AIPlayer(std::string inName) : Player(inName) {}

// ИИ оставит одну спичку, если это возможно. Иначе возьмет случайное количество
// спичек
unsigned AIPlayer::getMove(unsigned min, unsigned max, unsigned remainder) {
  if (max == remainder)
    return max - 1;

  return std::rand() % (max - min + 1) + min;
}