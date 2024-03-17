#include "cpu.h"
#include "ram.h"
#include <iostream>

void compute(void) {
  int buffer[BUF_SIZE];
  read(buffer);
  int sum = 0;
  for (int i = 0; i < BUF_SIZE; i++)
    sum += buffer[i];
  std::cout << sum << std::endl;
}