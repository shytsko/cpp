#include "ram.h"

int ram[BUF_SIZE]{};

void read(int *buf) {

  for (int i = 0; i < BUF_SIZE; i++)
    buf[i] = ram[i];
}
void write(const int *buf) {
  for (int i = 0; i < BUF_SIZE; i++)
    ram[i] = buf[i];
}