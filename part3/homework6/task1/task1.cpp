/*Используя функцию получения текущего времени std::time, реализуйте простейший
менеджер учёта времени. Пользователь взаимодействует с программой с помощью
команд: • Команда begin начинает отслеживание новой задачи. После ввода этой
команды пользователь должен ввести название задачи, над которой он планирует
сейчас работать. Если уже была начата какая-то другая задача, предыдущая должна
быть автоматически завершена и начата новая. • Команда end заканчивает
отслеживание текущей задачи. Если текущей начатой задачи нет, то команда ничего
не делает. • Команда status выводит на экран информацию о всех законченных
задачах и времени, которое было на них потрачено. Также выводится название
текущей выполняемой задачи, если таковая имеется. • Команда exit выходит из
программы.*/

#include <ctime>
#include <iostream>
#include <list>
#include <string>

#define SECUNDS_IN_HOUR 3600
#define SECUNDS_IN_MINUTE 60

struct Task {
  std::time_t begin = 0;
  std::time_t end = 0;
  std::string title;
};

// Создание новой задачи
void beginNewTask(std::list<Task> &tasks) {
  tasks.push_back(Task());
  std::cout << "Enter title of new task" << std::endl << "> ";
  std::getline(std::cin, tasks.back().title);
  tasks.back().begin = std::time(nullptr);
}

// Завершение последней задачи, если задача существует и еще не завершена
void endLastTask(std::list<Task> &tasks) {
  if (!tasks.empty() && tasks.back().end == 0)
    tasks.back().end = std::time(nullptr);
}

// Вывод информации о задаче
void viewTaskStatus(const Task &task) {
  std::cout << "Task \"" << task.title << '\"';
  if (task.end == 0) {
    std::cout << " in progress" << std::endl;
  } else {
    long int secundes = task.end - task.begin;
    long int hours = secundes / SECUNDS_IN_HOUR;
    secundes %= SECUNDS_IN_HOUR;
    long int minutes = secundes / SECUNDS_IN_MINUTE;
    secundes %= SECUNDS_IN_MINUTE;
    std::cout << " completed in " << hours << " hours " << minutes
              << " minutes " << secundes << " secunds" << std::endl;
  }
}

// Вывод информации обо всех задачах в списке
void viewStatus(std::list<Task> &tasks) {
  std::cout << "=============== STATUS ===============" << std::endl;
  for (const Task &task : tasks)
    viewTaskStatus(task);
  std::cout << "======================================" << std::endl;
}

int main() {
  std::list<Task> tasks;
  std::string command;

  while (true) {
    std::cout << "Enter command:" << std::endl
              << "begin - start new task" << std::endl
              << "end - end current task" << std::endl
              << "status - view status of tasks" << std::endl
              << "exit - exit the program" << std::endl
              << "> ";
    std::getline(std::cin, command);
    if (command == "begin") {
      endLastTask(tasks);
      beginNewTask(tasks);
    } else if (command == "end") {
      endLastTask(tasks);
    } else if (command == "status") {
      viewStatus(tasks);
    } else if (command == "exit") {
      break;
    } else {
      std::cout << "Command not recognized" << std::endl;
    }
  }

  return 0;
}
