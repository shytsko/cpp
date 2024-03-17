#include "gpu.h"
#include "ram.h"
#include <iostream>

void display(void) {
  int buffer[BUF_SIZE];
  read(buffer);
  for (int i = 0; i < BUF_SIZE; i++)
    std::cout << buffer[i] << ' ';
  std::cout << std::endl;
}