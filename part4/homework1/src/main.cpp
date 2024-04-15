#include "ai_player.h"
#include "game.h"
#include "human_player.h"
#include <iostream>
#include <memory>

int main() {
  std::shared_ptr<Player> player1 = std::make_shared<HumanPlayer>("Human");
  std::shared_ptr<Player> player2 = std::make_shared<AIPlayer>("Robot");

  Game game(player1, player2, 50, 5);

  player1.reset();
  player2.reset();

  player1 = game.run();

  std::cout << "Won " << player1->getName() << "!!!" << std::endl;

  return 0;
}
