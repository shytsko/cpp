#include "kbd_.h"
#include "ram.h"
#include <iostream>

void input(void) {
  int buffer[BUF_SIZE];
  for (int i = 0; i < BUF_SIZE; i++)
    std::cin >> buffer[i];
  write(buffer);
}