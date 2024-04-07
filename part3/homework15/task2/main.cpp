/*Реализуйте простую игру-симуляцию ловли рыбы. Игровое поле представляет собой
девять секторов условного пруда. В начале игры в одном из этих секторов с
помощью генератора случайных чисел оказывается рыба. Точно так же, случайным
образом, по секторам пруда распределяются и три сапога. Сапог и рыба при этом не
могут находиться в одном и том же секторе одновременно, как и несколько сапог
сразу в одном из секторов. Игрок закидывает удочку с приманкой в один из
секторов, номер которого вводится стандартным способом через консоль. Задача
игрока — угадать сектор, в котором находится рыба и, таким образом, поймать её.
Если игрок попал на пустой сектор, то удочку надо забросить повторно. Если игрок
поймал сапог, то игра завершается с отрицательным результатом. Реализовать
задачу нужно с помощью исключений: когда успешный заброс удочки генерирует
специальное пользовательское исключение, после чего программа должна завершиться
и оповестить пользователя об успешной рыбалке и количестве попыток, которое ему
для этого потребовалось. Если же был пойман сапог, то должно выводиться
сообщение о неудачной ловле*/

#include <cstdlib>
#include <ctime>
#include <exception>
#include <iostream>
#include <map>
#include <stdexcept>
#include <string>
#include <vector>

// Базовый класс для пользовательских исключений
class Caught : public std::exception {
  std::string message;

protected:
  Caught(const std::string &message) noexcept : message{message} {}

public:
  const char *what() const noexcept override { return message.c_str(); }
};

// Поймали рыбу
class Fish : public Caught {
public:
  Fish() noexcept : Caught("You caught a fish!!!") {}
};

// Поймали сапог
class Boot : public Caught {
public:
  Boot() noexcept : Caught("You caught the boot :(") {}
};

// Ничего не поймали
class Nothing : public Caught {
public:
  Nothing() noexcept : Caught("You didn't catch anything") {}
};

class GameFishing {

  // Игровой поле содержит одно из возможных значений
  enum class CaughtType { Nothing, Fish, Boot };
  std::vector<CaughtType> board;

  // Счетчик попыток
  int attemptCounter;

public:
  GameFishing(int boardSize, int numberFish, int numberBoots) {
    if (numberFish + numberBoots > boardSize)
      throw std::invalid_argument("The total number of fish and boots cannot "
                                  "exceed the size of the playing field");

    board.resize(boardSize);

    // Сначала все поля пустые
    for (int i = 0; i < board.size(); i++)
      board[i] = CaughtType::Nothing;

    std::srand(std::time(nullptr));

    // Размещаем рыб
    int counter = 0;
    while (counter < numberFish) {
      int i = std::rand() % board.size();
      if (board[i] == CaughtType::Nothing) {
        board[i] = CaughtType::Fish;
        counter++;
      }
    }

    // Размещаем сапоги
    counter = 0;
    while (counter < numberBoots) {
      int i = std::rand() % board.size();
      if (board[i] == CaughtType::Nothing) {
        board[i] = CaughtType::Boot;
        counter++;
      }
    }

    attemptCounter = 0;
  }

  // Основная логика игры. Передется номер поля в котором будем ловить.
  // В зависимости от содержания поля выбрасывается соответствующее исключенние
  // Если номер поля не корректный, также выбрасывается исключение
  void fishing(int field) {
    if (field < 1 || field > board.size())
      throw std::invalid_argument("The field must be from 1 to " +
                                  std::to_string(board.size()));

    attemptCounter++;

    switch (board[field - 1]) {
    case CaughtType::Fish:
      throw Fish();
      break;
    case CaughtType::Boot:
      throw Boot();
      break;
    default:
      throw Nothing();
      break;
    }
  }

  int getBoardSize(void) { return board.size(); }

  int getNumberAttempts(void) { return attemptCounter; };
};

int main() {
  GameFishing game(9, 1, 3);

  while (true) {
    std::cout << "Enter the number of the field where to cast your fishing rod "
              << "(from 1 to " << game.getBoardSize() << " ) > ";

    int field;
    std::cin >> field;
    try {
      game.fishing(field);
    } catch (const Fish &ex) {
      std::cout << ex.what() << std::endl;
      std::cout << "It took attempts: " << game.getNumberAttempts()
                << std::endl;
      return 0;
    } catch (const Boot &ex) {
      std::cout << ex.what() << std::endl;
      return -1;
    } catch (const Nothing &ex) {
      std::cout << ex.what() << std::endl;
    } catch (const std::invalid_argument &ex) {
      std::cout << ex.what() << std::endl;
    }
  }

  return 0;
}
