/*Реализуйте работу точного таймера с визуальной отдачей.
В начале программы пользователь вводит количество минут и секунд, которые
требуется засечь на таймере, и нажимает «Ввод». После этого начинается обратный
отсчёт времени, о чём незамедлительно и последовательно сообщается пользователю.
Формат вывода такой же, как и при вводе интервала: минуты и секунды. Как только
отсчёт на таймере иссяк, программа сообщает об этом с помощью вывода в консоль
специального сообщения. Сообщение вместо аудиосигнала может выглядеть так: DING!
DING! DING!*/

#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

int main() {
  std::cout << "Enter timer value (MM:SS): ";
  std::tm _tm{};
  std::cin >> std::get_time(&_tm, "%M:%S");

  std::time_t currentTime = std::time(nullptr);
  std::time_t endTime = currentTime + _tm.tm_min * 60 + _tm.tm_sec;
  std::time_t delta{}, prevDelta{};

  do {
    delta = (std::time_t)std::difftime(endTime, currentTime);
    if (delta != prevDelta) {
      std::cout << std::put_time(std::localtime(&delta), "%M:%S") << std::endl;
      prevDelta = delta;
    }
    currentTime = std::time(nullptr);
  } while (currentTime <= endTime);

  std::cout << "DING! DING! DING!" << std::endl;

  return 0;
}
