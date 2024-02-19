/*Требуется создать простую программу записи ведомость.
Формат ведомости прежний. Сначала идёт имя и фамилия получателя денежных
средств, далее располагается дата выдачи в формате ДД.ММ.ГГГГ. Завершает запись
сумма выплаты в рублях. Данные разделяются между собой пробелами. В конце каждой
записи должен быть расположен перевод строки.
При старте программы пользователь последовательно вводит данные для новой
записи, которые записываются затем в файл в текстовом режиме. Программа должна
добавлять новые записи в конец файла, не удаляя его текущее содержимое.*/

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

bool validateDateFormat(std::string date) {
  size_t dotFirst = date.find('.');
  size_t dotSecond = date.rfind('.');
  if (date.length() != 10 || dotFirst != 2 || dotSecond != 5)
    return false;

  int day = std::stoi(date.substr(0, 2));
  int month = std::stoi(date.substr(3, 2));
  int year = std::stoi(date.substr(6, 4));

  if (day < 1 || day > 31)
    return false;

  if (month < 1 || month > 12)
    return false;

  return true;
}

int main() {
  std::string firstName;
  std::string lastName;
  std::string date;
  int salary;

  std::cout << "First name: ";
  std::cin >> firstName;
  std::cout << "Last name: ";
  std::cin >> lastName;
  std::cout << "Date (DD.MM.YYYY): ";
  std::cin >> date;
  if (!validateDateFormat(date)) {
    std::cout << "Not valid date format" << std::endl;
    exit(-1);
  }

  std::cout << "Salary: ";
  std::cin >> salary;

  std::ofstream file("salary.txt", std::ios::app);

  if (file.is_open()) {
    file << firstName << ' ' << lastName << ' ' << date << ' ' << salary
         << std::endl;
    std::cout << "Record saved" << std::endl;
    file.close();
  } else {
    std::cout << "Failed to save record" << std::endl;
  }
}