/*Требуется реализовать упрощённую симуляцию работы банкомата. В банкомате могут
храниться только бумажные купюры номиналом от 100 до 5000 рублей. Максимально в
банкомате может храниться только 1000 купюр. Все они записываются в отдельный
файл. У банкомата, как у устройства, две основных операции — снятие денег
пользователем и наполнение деньгами инкассаторами банка.

Наполнение банкомата происходит, если при старте программы в консоль вводится
символ плюс “+”. Количество купюр рассчитывается так, чтобы банкомат был
заполнен полностью. Все купюры при этом выбираются случайным образом. Если на
старте программы в консоль вводится минус (“-”), то симулируется снятие
пользователем денег. Пользователь указывает сумму с точностью до 100 рублей. Мы
будем считать, что каждый клиент обладает неограниченным балансом в системе и
теоретически может снять любую сумму. На практике, если данная сумма не может
быть снята из-за отсутствия подходящих денег в машине, показывается сообщение,
что эта операция невозможна. После выполнения любой из операций программа
завершает выполнение. Состояние банкомата должно храниться в отдельном бинарном
файле, автономно.*/

#include <algorithm>
#include <cstddef>
#include <ctime>
#include <fstream>
#include <iostream>

#define DENOM_NUMB 6
#define ATM_CAPACITY 1000

#define OK 0
#define BAD_FORMAT -1
#define CRC_ERROR -2
#define NO_FILE -3

int loadData(const char *filePath, int *data, size_t size) {
  int rerutn_code = OK;
  std::ifstream file(filePath, std::ios::binary);
  if (file.is_open()) {
    file.read((char *)data, size * sizeof(int));
    if (file.gcount() == size * sizeof(int)) {
      int crc;
      file.read((char *)&crc, sizeof(int));
      if (file.gcount() == sizeof(int)) {
        int sum = 0;
        for (size_t i = 0; i < size; i++)
          sum += *(data + i);
        if (sum != crc)
          rerutn_code = CRC_ERROR;
      } else {
        rerutn_code = BAD_FORMAT;
      }
    } else {
      rerutn_code = BAD_FORMAT;
    }
  } else {
    rerutn_code = NO_FILE;
  }

  return rerutn_code;
}

int saveData(const char *filePath, const int *data, size_t size) {
  std::ofstream file(filePath, std::ios::binary);
  if (file.is_open()) {
    int crc = 0;
    for (size_t i = 0; i < size; i++)
      crc += *(data + i);
    file.write((char *)data, size * sizeof(int));
    file.write((char *)&crc, sizeof(int));
    file.close();
  } else {
    return NO_FILE;
  }
  return OK;
}

void printData(const int *data, const int *denom, size_t size) {
  int totalAmount = 0;
  int totalBanknotes = 0;
  std::cout << "===== Current status =====" << std::endl;
  std::cout << "Denomination\tBanknotes" << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << *(denom + i) << "\t\t" << *(data + i) << std::endl;
    totalBanknotes += *(data + i);
    totalAmount += *(data + i) * *(denom + i);
  }
  std::cout << "Total amount: " << totalAmount << std::endl;
  std::cout << "Total banknotes: " << totalBanknotes << std::endl;
}

int main() {
  const char *filePath = "atm.bin";
  int denominations[] = {5000, 2000, 1000, 500, 200, 100};

  int numberBanknotes[DENOM_NUMB];

  int res = loadData(filePath, numberBanknotes, DENOM_NUMB);

  if (res == NO_FILE) {
    for (size_t i = 0; i < DENOM_NUMB; i++)
      numberBanknotes[i] = 0;
  } else if (res == BAD_FORMAT || res == CRC_ERROR) {
    std::cout << "ATM malfunction!" << std::endl;
    exit(-1);
  }

  int numberBanknotesTotal = 0;
  for (size_t i = 0; i < DENOM_NUMB; i++)
    numberBanknotesTotal += numberBanknotes[i];

  printData(numberBanknotes, denominations, DENOM_NUMB);

  char mode;
  std::cout << "Mode ('+' - refill, '-' - cash): ";
  std::cin >> mode;
  if (mode == '+') {
    std::srand(std::time(nullptr));
    for (int i = numberBanknotesTotal; i < ATM_CAPACITY; i++)
      numberBanknotes[std::rand() % DENOM_NUMB]++;

    res = saveData(filePath, numberBanknotes, DENOM_NUMB);
    if (res == OK) {
      std::cout << "ATM is full" << std::endl;
    } else {
      std::cout << "ATM malfunction!" << std::endl;
      exit(-1);
    }

  } else if (mode == '-') {
    std::cout << "Amount for cash: ";
    int amount;
    std::cin >> amount;
    if (amount % 100 != 0) {
      std::cout << "The amount must be a multiple of 100" << std::endl;
      exit(-1);
    }
    int numberBanknotesForCash[DENOM_NUMB] = {0, 0, 0, 0, 0, 0};
    int remainingAmount = amount;
    for (int i = 0; remainingAmount > 0 && i < DENOM_NUMB; i++) {
      numberBanknotesForCash[i] =
          std::min(remainingAmount / denominations[i], numberBanknotes[i]);
      remainingAmount -= denominations[i] * numberBanknotesForCash[i];
    }

    if (remainingAmount != 0) {
      std::cout << "It is impossible to issue this amount" << std::endl;
      exit(-1);
    }

    int checkAmount = 0;
    for (int i = 0; i < DENOM_NUMB; i++)
      checkAmount += numberBanknotesForCash[i] * denominations[i];
    if (checkAmount != amount) {
      std::cout << "ATM malfunction!" << std::endl;
      exit(-1);
    }

    for (int i = 0; i < DENOM_NUMB; i++) {
      numberBanknotes[i] -= numberBanknotesForCash[i];
    }

    if (saveData(filePath, numberBanknotes, DENOM_NUMB) == OK) {
      for (int i = 0; i < DENOM_NUMB; i++)
        if (numberBanknotesForCash[i])
          std::cout << numberBanknotesForCash[i] << " banknotes of "
                    << denominations[i] << "rubles were issued" << std::endl;
    } else {
      std::cout << "ATM malfunction!" << std::endl;
      exit(-1);
    }

  } else {
    std::cout << "Not the correct mode" << std::endl;
  }
  printData(numberBanknotes, denominations, DENOM_NUMB);
}
