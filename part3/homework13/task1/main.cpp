/*1. Реализуйте класс Dog, который использует стандартный умный указатель
shared_ptr для класса Toy.
2. Реализуйте у класса Dog метод getToy, с помощью которого собака подбирает
игрушку. — Если у собаки уже есть эта игрушка, необходимо вывести в консоль
фразу: I already have this toy. — Если в данный момент игрушка находится у
другой собаки, нужно вывести в консоль: Another dog is playing with this toy. —
Если игрушка свободна, собака подбирает её.
3. Реализуйте у класса Dog метод dropToy, с помощью которого собака бросает
игрушку на пол, после чего другая может подобрать её. — Если у собаки в этот
момент нет игрушки, в консоль необходимо вывести: Nothing to drop.*/

#include <iostream>
#include <memory>
#include <string>

class Toy {
  std::string name;

public:
  Toy(const std::string &inName) : name(inName) {}
  std::string getName() { return name; }
  ~Toy() { std::cout << "Toy " << name << " was destroyed " << std::endl; }
};

class Dog {
  std::string name;
  std::shared_ptr<Toy> toy;

public:
  Dog(const std::string &inName) : name(inName), toy(nullptr) {}

  void dropToy() {
    if (toy)
      toy.reset();
    else
      std::cout << "Nothing to drop." << std::endl;
  }

  void getToy(std::shared_ptr<Toy> &newToy) {
    if (!newToy) {
      std::cout << "There is no toy." << std::endl;
      return;
    }

    if (newToy == toy) {
      std::cout << "I already have this toy." << std::endl;
      return;
    }

    if (newToy.use_count() > 1) {
      std::cout << "Another dog is playing with this toy." << std::endl;
      return;
    }

    if (toy)
      dropToy();
    toy = newToy;
  }
};

int main() {
  std::shared_ptr<Toy> ball = std::make_shared<Toy>("Ball");
  std::shared_ptr<Toy> duck = std::make_shared<Toy>("Duck");

  Dog pirat("Pirat");
  Dog bobik("Bobik");

  pirat.getToy(ball);
  pirat.getToy(ball);
  bobik.getToy(duck);
  pirat.getToy(duck);
  bobik.dropToy();
  pirat.getToy(duck);
  pirat.dropToy();
  pirat.dropToy();

  return 0;
}
