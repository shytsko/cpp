#include "game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <memory>

Game::Game(std::shared_ptr<Player> &player1, std::shared_ptr<Player> &player2,
           unsigned matches, unsigned _maxMove)
    : matchesLeft{matches}, maxMove{_maxMove} {
  players[0] = player1;
  players[1] = player2;
}

std::shared_ptr<Player> Game::run(void) {
  // Игрок, который будет ходить первым, определяется случайно
  std::srand(std::time(nullptr));
  currentPlayer = std::rand() % 2;

  while (true) {
    std::cout << "Matches left: " << matchesLeft << std::endl;
    std::cout << "Player move: " << players[currentPlayer]->getName()
              << std::endl;

    // Получение хода от игрока
    unsigned move = players[currentPlayer]->getMove(
        1, std::min(maxMove, matchesLeft), matchesLeft);

    std::cout << "Player " << players[currentPlayer]->getName() << " took "
              << move << " matches" << std::endl;

    matchesLeft -= move;

    // Если осталась только одна спичка, текущий игров выиграл
    if (matchesLeft == 1)
      return players[currentPlayer];

    currentPlayer = ++currentPlayer % 2;

    // Если спичек не осталось, выиграл следующий игрок
    if (matchesLeft == 0)
      return players[currentPlayer];
  }
}