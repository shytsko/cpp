/* Все наши животные могут мяукать и гавкать, то есть издавать звуки в
 * соответствии со своим классом. Но что, если нужно добавить им новое
 * поведение, например, научить плавать или стоять на задних лапах. Рассмотрим
 * класс Dog: все собаки умеют лаять и бегать, а некоторые собаки умеют хорошо
 * плавать. Чтобы добавить эти качества классу Dog, мы можем создать ещё один
 * класс «плавающих» животных и наследовать от него наш класс. Но что, если не
 * все собаки умеют хорошо плавать, а некоторые из них совсем не умеют
 * плавать.Наша задача — построить класс Dog таким образом, чтобы к его объектам
 * можно было выборочно добавлять новые умения, но при этом не менять поведение
 * основного класса. Список умений будет вызываться с помощью метода
 * show_talents().
 */

#include <iostream>
#include <string>
#include <vector>

class Talent {
public:
  virtual std::string getTitle(void) const = 0;
  virtual ~Talent(void){};
};

class Swimming : public Talent {
public:
  ~Swimming(void) override {}
  std::string getTitle(void) const override { return "swimming"; }
};

class Dancing : public Talent {
public:
  ~Dancing(void) override {}
  std::string getTitle(void) const override { return "dancing"; }
};

class Counting : public Talent {
public:
  ~Counting(void) override {}
  std::string getTitle(void) const override { return "counting"; }
};

class Animal {
protected:
  std::string name;
  std::vector<Talent *> talents;

public:
  Animal(std::string inName) : name(inName) {}

  std::string getName(void) { return name; }

  virtual void voice() = 0;

  Animal *addTalent(Talent *newTalent) {
    talents.push_back(newTalent);
    return this;
  }

  const std::vector<Talent *> &getTalents(void) { return talents; }

  virtual ~Animal(void) {
    while (!talents.empty()) {
      delete talents.back();
      talents.pop_back();
    }
  };
};

class Dog : public Animal {
public:
  Dog(std::string inName) : Animal(inName) {}
  ~Dog(void) override {}
  void voice() override { std::cout << name << ": Gav" << std::endl; }
};

class Cat : public Animal {
public:
  Cat(std::string inName) : Animal(inName) {}
  ~Cat(void) override {}
  void voice() override { std::cout << name << ": Myau" << std::endl; }
};

int main() {
  Animal *cat = new Cat("Barsik");
  cat->addTalent(new Dancing())->addTalent(new Counting());

  Animal *dog = new Dog("Reks");
  dog->addTalent(new Swimming());

  cat->voice();
  dog->voice();

  std::cout << cat->getName() << " can: ";
  for (const Talent *talent : cat->getTalents())
    std::cout << talent->getTitle() << ", ";
  std::cout << std::endl;

  std::cout << dog->getName() << " can: ";
  for (const Talent *talent : dog->getTalents())
    std::cout << talent->getTitle() << ", ";
  std::cout << std::endl;

  delete cat;
  delete dog;

  return 0;
}
