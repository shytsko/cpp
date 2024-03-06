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

struct Item
{
  std::string name;
  std::time_t birthDate;
};

bool inputTime(std::tm *_tm, const char *format)
{
  std::string dateString;
  std::getline(std::cin, dateString);
  std::istringstream ss(dateString);
  ss >> std::get_time(_tm, format);
  return !(ss.fail() || _tm->tm_mday == 0);
}

std::time_t getTimeToday(const std::tm *tmNow)
{
  std::tm _tm = *tmNow;
  _tm.tm_sec = 0;
  _tm.tm_min = 0;
  _tm.tm_hour = 0;
  return std::mktime(&_tm);
}

std::time_t getBirthDay(time_t birthDate, int year)
{
  std::tm *_tm = std::localtime(&birthDate);
  _tm->tm_year = year;
  return std::mktime(_tm);
}

std::time_t getLastDayInYear(int year)
{
  std::tm _tm{};
  _tm.tm_sec = 59;
  _tm.tm_min = 59;
  _tm.tm_hour = 23;
  _tm.tm_mday = 31;
  _tm.tm_mon = 11;
  _tm.tm_year = year;
  return std::mktime(&_tm);
}

int main()
{

  std::list<Item> birthDates;

  while (true)
  {
    std::string name;
    std::cout << "Enter a name or \"end\" to complete the entry" << std::endl
              << "> ";
    std::getline(std::cin, name);
    if (name != "end")
    {
      std::tm date{};
      std::cout << "Enter date of birth in the format Y/m/d" << std::endl
                << "> ";
      if (inputTime(&date, DATE_FORMAT))
        birthDates.push_back({name, std::mktime(&date)});
      else
        std::cout << "Invalid date" << std::endl;
    }
    else
    {
      break;
    }
  }

  std::time_t now = time(nullptr);
  std::tm *tmNow = std::localtime(&now);
  std::time_t today = getTimeToday(tmNow);

  for (const Item &item : birthDates)
  {
    std::time_t birthDay = getBirthDay(item.birthDate, tmNow->tm_year);
    if (birthDay == today)
      std::cout << item.name << " celebrates his birthday today" << std::endl;
  }

  return 0;
}
