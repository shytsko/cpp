/*Используя макросы, реализуйте небольшую программу по вводу дня недели и выводу
этого дня недели в текстовом виде в консоль. В начале программы пользователь
вводит день недели в виде его порядкового номера. В результате в консоли
появляется буквенное отображение этого дня недели. В этом упражнении запрещается
использовать классические переменные, кроме как для хранения ввода пользователя.
Использовать строковые литералы напрямую тоже нельзя. Всё должно быть
реализовано исключительно на макросах.*/

#include <iostream>

#define MONDAY 1
#define TUESDAY 2
#define WEDNESDAY 3
#define THURSDAY 4
#define FRIDAY 5
#define SATURDAY 6
#define SUNDAY 7

#define DAY_STR(d) d##_STR

#define MONDAY_STR ("Monday")
#define TUESDAY_STR ("Tuesday")
#define WEDNESDAY_STR ("Wednesday")
#define THURSDAY_STR ("Thursday")
#define FRIDAY_STR ("Friday")
#define SATURDAY_STR ("Saturday")
#define SUNDAY_STR ("Sunday")

int main() {
  std::cout << "Enter days number: ";
  int day;
  std::cin >> day;

  switch (day) {
  case MONDAY:
    std::cout << DAY_STR(MONDAY) << std::endl;
    break;
  case TUESDAY:
    std::cout << DAY_STR(TUESDAY) << std::endl;
    break;
  case WEDNESDAY:
    std::cout << DAY_STR(WEDNESDAY) << std::endl;
    break;
  case THURSDAY:
    std::cout << DAY_STR(THURSDAY) << std::endl;
    break;
  case FRIDAY:
    std::cout << DAY_STR(FRIDAY) << std::endl;
    break;
  case SATURDAY:
    std::cout << DAY_STR(SATURDAY) << std::endl;
    break;
  case SUNDAY:
    std::cout << DAY_STR(SUNDAY) << std::endl;
    break;

  default:
    std::cout << "Incorrect day of the week number" << std::endl;
    break;
  }
}
