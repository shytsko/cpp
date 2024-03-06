/*Реализуйте простую программу по вычислению ближайшего дня рождения.
В начале программы пользователь последовательно вводит данные о днях рождения
своих друзей: вводит имя друга и саму дату рождения полностью, включая месяц и
год, в формате год/месяц/день. Сигналом окончания ввода дней рождения является
“end” введённое в качестве имени. После этого программа вычисляет ближайший день
рождения по отношению к текущему времени и выводит его на экран вместе с именем
в удобном, локальном формате - м . Если день рождения уже был в этом
году, данные о пользователе пропускаются. Если у кого-то из друзей день рождения
сегодня, то в консоль выводится специальное сообщение об этом. Учтите, что таких
сообщений может быть несколько, ведь сразу несколько людей могут иметь дни
рождения в один день.*/

#include <ctime>
#include <iomanip>
#include <iostream>
#include <list>
#include <sstream>
#include <string>

#define DATE_FORMAT "%Y/%m/%d"

struct Item {
  std::string name;
  std::tm birthDate;
};

bool inputTime(std::tm *_tm, const char *format) {
  std::string dateString;
  std::getline(std::cin, dateString);
  std::istringstream ss(dateString);
  ss >> std::get_time(_tm, format);
  return !(ss.fail() || _tm->tm_mday == 0);
}

int main() {

  std::list<Item> birthDates;

  while (true) {
    std::string name;
    std::cout << "Enter a name or \"end\" to complete the entry" << std::endl
              << "> ";
    std::getline(std::cin, name);
    if (name != "end") {
      std::tm date = {};
      std::cout << "Enter date of birth in the format Y/m/d" << std::endl
                << "> ";
      if (inputTime(&date, DATE_FORMAT))
        birthDates.push_back({name, date});
      else
        std::cout << "Invalid date" << std::endl;
    } else {
      break;
    }
  }

  for (const Item &item : birthDates) {
    std::cout << std::put_time(&(item.birthDate), DATE_FORMAT) << std::endl;
  }

  return 0;
}
