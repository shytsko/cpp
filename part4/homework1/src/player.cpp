#include "player.h"

Player::Player(std::string inName) : name{inName} {}

std::string Player::getName(void) { return name; }