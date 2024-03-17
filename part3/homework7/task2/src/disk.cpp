#include "disk.h"
#include "ram.h"
#include <fstream>
#include <iostream>

void load(void) {
  int buffer[BUF_SIZE];
  std::ifstream file(FILE_PATH);

  if (file.is_open()) {
    for (int i = 0; i < BUF_SIZE; i++)
      file >> buffer[i];
    write(buffer);
    file.close();
  } else {
    std::cerr << "Failed to open file: " << FILE_PATH << std::endl;
  }
}

void save(void) {
  int buffer[BUF_SIZE];
  std::ofstream file(FILE_PATH);
  read(buffer);
  if (file.is_open()) {
    for (int i = 0; i < BUF_SIZE; i++)
      file << buffer[i] << std::endl;
    file.close();
  } else {
    std::cerr << "Failed to open file: " << FILE_PATH << std::endl;
  }
}