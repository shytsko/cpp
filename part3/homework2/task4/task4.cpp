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

#define DENOM_NUMB 6         // Количество номиналов банкнот
#define ATM_CAPACITY 1000    // Количество банкнот, которое можно загрузить а банкомат

// Коды результатов сохранения в фал или чтения из файла 
#define OK 0              // Успешно
#define BAD_FORMAT -1     // Не верный формат файла 
#define CRC_ERROR -2      // Ошибка контрольой суммы
#define NO_FILE -3        // Нет файла

// Формат файла:
// Бинарный формат. Сначала расположени массив типа int, размер массива указывается. 
// В конце контролльная сумма типа int, контрольная сумма равна сумме элементов массива

// Чтение данных из файла
// filePath - имя файла
// data - масив, в который необходимо сохранить данные
// size - размер массива
int loadData(const char *filePath, int *data, size_t size) {
  int rerutn_code = OK;
  std::ifstream file(filePath, std::ios::binary);
  if (file.is_open()) {                            // Проверка, открыт ли файл
    file.read((char *)data, size * sizeof(int));   // Чтение массива
    if (file.gcount() == size * sizeof(int)) {     // Проверка количества считанных байт
      int crc;  
      file.read((char *)&crc, sizeof(int));        // чтение контрольной суммы
      if (file.gcount() == sizeof(int)) {          // Проверка количества считанных байт
        int sum = 0;
        for (size_t i = 0; i < size; i++)          // Подсчет суммы элементов считаного массива
          sum += *(data + i);
        if (sum != crc)                            // Проверка контрольной суммы
          rerutn_code = CRC_ERROR;                 // Ошибка при подсчете контрольной суммы
      } else {
        rerutn_code = BAD_FORMAT;                  // Ошибка при чтении основных данных
      }
    } else {
      rerutn_code = BAD_FORMAT;                    // Ошибка при чтении контрольной суммы
    }
  } else {
    rerutn_code = NO_FILE;                         // Ошибка, если файла нет
  }

  return rerutn_code;
}


// Запись файла
// filePath - имя файла
// data - масив с данными
// size - размер массива
int saveData(const char *filePath, const int *data, size_t size) {
  std::ofstream file(filePath, std::ios::binary);
  if (file.is_open()) {                              // Проверка, открыт ли файл
    int crc = 0;
    for (size_t i = 0; i < size; i++)                // Подсчет контрольной суммы
      crc += *(data + i);
    file.write((char *)data, size * sizeof(int));    // Запись массива
    file.write((char *)&crc, sizeof(int));           // Запись контрольной суммы
    file.close();
  } else {
    return NO_FILE;
  }
  return OK;
}


// Вывод состояния банкомата
// data - массив с количеством банкнот каждого номинала
// denom - массив с номиналами банкнот
// size - размер массивов data и denom
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
  int denominations[] = {5000, 2000, 1000, 500, 200, 100};  // массив с номиналами

  int numberBanknotes[DENOM_NUMB];                          // массив с количеством банкнот каждого номинала

  int res = loadData(filePath, numberBanknotes, DENOM_NUMB);  // загрузка из файла

  if (res == NO_FILE) {                                       // если файла не существует
    for (size_t i = 0; i < DENOM_NUMB; i++)                   // инициализация нулями (банкомат пустой)
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
  if (mode == '+') {                                              // режим заполнения
    std::srand(std::time(nullptr));
    for (int i = numberBanknotesTotal; i < ATM_CAPACITY; i++)     // заполнение случайными банкнотами до максимального количества
      numberBanknotes[std::rand() % DENOM_NUMB]++;

    res = saveData(filePath, numberBanknotes, DENOM_NUMB);        // сохранение данных в файл
    if (res == OK) {
      std::cout << "ATM is full" << std::endl;
    } else {
      std::cout << "ATM malfunction!" << std::endl;
      exit(-1);
    }

  } else if (mode == '-') {                                        // режим выдачи
    std::cout << "Amount for cash: ";
    int amount;
    std::cin >> amount;                                            // ввод суммы для выдачи
    if (amount % 100 != 0) {                                       // проверка суммы для выдачи на кратность минимальному номиналу
      std::cout << "The amount must be a multiple of 100" << std::endl;
      exit(-1);
    }
    int numberBanknotesForCash[DENOM_NUMB] = {0, 0, 0, 0, 0, 0};    // массив с количество банкнот для выдачи
    int remainingAmount = amount;                        
    for (int i = 0; remainingAmount > 0 && i < DENOM_NUMB; i++) {              // набор банкнот каждого номинала для выдачи
      numberBanknotesForCash[i] =                                              // количество определяется как минимальное из остатка от деления 
          std::min(remainingAmount / denominations[i], numberBanknotes[i]);    // оставшейся суммы и количества банкнот в банкомате
      remainingAmount -= denominations[i] * numberBanknotesForCash[i];
    }

    if (remainingAmount != 0) {                                                // если оставшаяся сумма не равна нулю
      std::cout << "It is impossible to issue this amount" << std::endl;       // выдать запрошенную сумму невозможно
      exit(-1);
    }

    int checkAmount = 0;                                                       // контрольна проверка 
    for (int i = 0; i < DENOM_NUMB; i++)
      checkAmount += numberBanknotesForCash[i] * denominations[i];
    if (checkAmount != amount) {
      std::cout << "ATM malfunction!" << std::endl;
      exit(-1);
    }

    for (int i = 0; i < DENOM_NUMB; i++) {                         // корректировка остатка банкнот
      numberBanknotes[i] -= numberBanknotesForCash[i];
    }

    if (saveData(filePath, numberBanknotes, DENOM_NUMB) == OK) {   // сохранение данных и провека
      for (int i = 0; i < DENOM_NUMB; i++)                          // если сохранено успешно, выдача наличных
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
