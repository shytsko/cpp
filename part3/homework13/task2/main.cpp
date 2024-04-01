/*1. Реализуйте умный указатель shared_ptr_toy с распределённым доступом и
механикой подсчёта ссылок для класса Toy, реализованного в задании. Указатель
должен: — иметь все стандартные методы класса, — быть функциональной заменой
использованию shared_ptr<Toy>.
2. Реализуйте свободную функцию make_shared_toy, которая принимает набор
аргументов и конструирует игрушку от названия или при помощи копии другой
игрушки.*/

#include <iostream>
#include <string>

class Toy {
  std::string name;

public:
  Toy(const std::string &inName) : name(inName) {}

  //   Toy(const Toy &other) { name = other.name; }

  std::string getName() { return name; }

  ~Toy() { std::cout << "Toy " << name << " was destroyed " << std::endl; }
};

class SharedPtrToy {
  Toy *ptr;
  unsigned *counter;

public:
  SharedPtrToy(std::nullptr_t nPtr = nullptr) : ptr(nPtr), counter(nPtr) {}

  SharedPtrToy(Toy *newToy) {
    ptr = newToy;
    counter = new unsigned(1);
  }

  SharedPtrToy(const SharedPtrToy &other) {
    ptr = other.ptr;
    counter = other.counter;
    if (counter)
      (*counter)++;
  }

  SharedPtrToy &operator=(const SharedPtrToy &other) {
    if (this != &other) {
      reset();
      ptr = other.ptr;
      counter = other.counter;
      if (counter)
        (*counter)++;
    }

    return *this;
  }

  operator bool() const { return ptr != nullptr; }
  bool operator==(const SharedPtrToy &other) const { return ptr == other.ptr; }

  void reset() {
    if (ptr) {
      (*counter)--;
      if (*counter == 0) {
        delete ptr;
        delete counter;
      }
      ptr = nullptr;
      counter = nullptr;
    }
  }

  Toy *get() { return ptr; }

  unsigned useCount() { return *counter; }

  ~SharedPtrToy() { reset(); }
};

SharedPtrToy makeSharedToy(const Toy &otherToy) {
  Toy *toy = new Toy(otherToy);
  return SharedPtrToy(toy);
}

SharedPtrToy makeSharedToy(std::string name) {
  Toy *toy = new Toy(name);
  return SharedPtrToy(toy);
}

class Dog {
  std::string name;
  SharedPtrToy toy;

public:
  Dog(const std::string &inName) : name(inName), toy(nullptr) {}

  void dropToy() {
    if (toy)
      toy.reset();
    else
      std::cout << "Nothing to drop." << std::endl;
  }

  void getToy(SharedPtrToy &newToy) {
    if (!newToy) {
      std::cout << "There is no toy." << std::endl;
      return;
    }

    if (newToy == toy) {
      std::cout << "I already have this toy." << std::endl;
      return;
    }

    if (newToy.useCount() > 1) {
      std::cout << "Another dog is playing with this toy." << std::endl;
      return;
    }

    if (toy)
      dropToy();
    toy = newToy;
  }
};

int main() {
  SharedPtrToy ball = makeSharedToy("Ball");
  SharedPtrToy duck = makeSharedToy("Duck");

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
