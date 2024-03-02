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

#define DAY_STR(d) DAY_##d##_STR

#define DAY_1_STR ("Monday")
#define DAY_2_STR ("Tuesday")
#define DAY_3_STR ("Wednesday")
#define DAY_4_STR ("Thursday")
#define DAY_5_STR ("Friday")
#define DAY_6_STR ("Saturday")
#define DAY_7_STR ("Sunday")

int main() {
  std::cout << "Enter days number: ";
  int day;
  std::cin >> day;

  switch (day) {
  case MONDAY:
    std::cout << DAY_STR(1) << std::endl;
    break;
  case TUESDAY:
    std::cout << DAY_STR(2) << std::endl;
    break;
  case WEDNESDAY:
    std::cout << DAY_STR(3) << std::endl;
    break;
  case THURSDAY:
    std::cout << DAY_STR(4) << std::endl;
    break;
  case FRIDAY:
    std::cout << DAY_STR(5) << std::endl;
    break;
  case SATURDAY:
    std::cout << DAY_STR(6) << std::endl;
    break;
  case SUNDAY:
    std::cout << DAY_STR(7) << std::endl;
    break;

  default:
    std::cout << "Incorrect day of the week number" << std::endl;
    break;
  }
}
