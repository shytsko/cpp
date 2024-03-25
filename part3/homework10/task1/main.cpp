/*Реализуйте симуляцию состязаний по заплыву на 100 метров.
Всего шесть дорожек и шесть пловцов. Имена пловцов указываются вначале из
стандартного ввода. Каждый из них плывёт с разной скоростью, которая также
задаётся пользователем при старте, через стандартный ввод в метрах в секунду.
Каждую секунду в стандартный вывод выдаётся информация о том, сколько проплыл
тот или иной пловец. Как только все пловцы коснулись 100-метровой отметки,
заплыв заканчивается и выводится таблица с итоговыми результатами,
отсортированная по возрастанию итогового времени заплыва.*/
#include <ctime>
#include <iostream>
#include <list>
#include <mutex>
#include <string>
#include <thread>

#define NUMBER_TRACKS 6

std::list<std::string> winners;
std::mutex winnersLock;

std::mutex outputLock;

void swimming(std::string swimmerName, int speed, int distance) {
  int swimmerSwam = 0;
  int time = 0;

  outputLock.lock();
  std::cout << "The swimmer " << swimmerName << " started the swim."
            << std::endl;
  outputLock.unlock();

  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(1));
    swimmerSwam += speed;
    time++;
    if (swimmerSwam < distance) {
      outputLock.lock();
      std::cout << "In " << time << " s swimmer " << swimmerName << " swam "
                << swimmerSwam << " m" << std::endl;
      outputLock.unlock();
    } else
      break;
  }

  outputLock.lock();
  std::cout << "The swimmer " << swimmerName << " finished in " << time << " s."
            << std::endl;
  outputLock.unlock();

  winnersLock.lock();
  winners.push_back(swimmerName);
  winnersLock.unlock();
}

int main() {
  std::srand((unsigned)std::time(nullptr));

  std::thread *swims[NUMBER_TRACKS];

  for (int i = 0; i < NUMBER_TRACKS; i++) {
    swims[i] = new std::thread(swimming, "Swimmer" + std::to_string(i + 1),
                               std::rand() % 10 + 5, 100);
  }

  for (int i = 0; i < NUMBER_TRACKS; i++)
    swims[i]->join();

  int j = 0;
  outputLock.lock();
  std::cout << std::endl << "Results:" << std::endl;

  winnersLock.lock();
  for (std::string name : winners) {
    std::cout << ++j << ".\t" << name << std::endl;
  }
  winnersLock.unlock();
  outputLock.unlock();

  for (int i = 0; i < NUMBER_TRACKS; i++)
    delete swims[i];

  return 0;
}
