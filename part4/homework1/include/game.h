#ifndef H_GAME
#define H_GAME

#include "player.h"
#include <memory>

// Класс игры
class Game {
  // Массив с указателями на игроков
  std::shared_ptr<Player> players[2];

  // Текущий игрок
  size_t currentPlayer{0};

  // Осталось спичек
  unsigned matchesLeft;

  // Максимальное количество спичек, которое можно забрать за один ход
  unsigned maxMove;

public:
  Game(std::shared_ptr<Player> &_player1, std::shared_ptr<Player> &_player2,
       unsigned matches, unsigned maxMove);
  std::shared_ptr<Player> run(void);
};

#endif
