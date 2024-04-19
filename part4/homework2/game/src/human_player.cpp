#include "human_player.h"
#include <iostream>
#include <string>

HumanPlayer::HumanPlayer(std::string inName) : Player(inName) {}

unsigned HumanPlayer::getMove(unsigned min, unsigned max, unsigned remainder) {
  while (true) {
    std::cout << "How many matches do you want to take (" << min << "-" << max
              << ")? > ";

    unsigned input;
    std::cin >> input;

    if (input >= min && input <= max)
      return input;

    std::cout << "You entered an incorrect value. Please re-enter" << std::endl;
  }
}