/*Реализуйте программу чтения информации из ведомости по учёту выплат. Сама
ведомость представляет собой следующую таблицу:
• имя и фамилия человека;
• количество денег, которые были выплачены лицу;
• дата выплаты в формате ДД.ММ.ГГГГ.
На основе данных из ведомости следует подсчитать общее количество выплаченных
средств и определить человека с максимальной суммой выплат.*/

#include <fstream>
#include <iostream>
#include <string>

int main() {
  int maxSalary = 0;
  std::string maxSalaryEmployeeName = "";

  std::ifstream file("salary_statement.txt");

  if (file.is_open()) {
    int sumSalary = 0;

    while (!(file.eof())) {
      std::string firstName = "";
      std::string lastName = "";
      int salary = 0;
      std::string date = "";
      file >> firstName >> lastName >> salary >> date;
      sumSalary += salary;
      if (salary > maxSalary) {
        maxSalary = salary;
        maxSalaryEmployeeName = firstName + ' ' + lastName;
      }
    }
    file.close();

    std::cout << "Total salary: " << sumSalary << std::endl
              << "Employee with max salary: " << maxSalaryEmployeeName << " ("
              << maxSalary << ")" << std::endl;
  }
}