/*С помощью шаблонов реализуйте простой класс реестра, хранящий произвольные
типы значений по ключам произвольного типа. Ключи при этом могут повторяться.
Реестр должен поддерживать следующие операции: добавление элемента с ключом,
удаление элементов с заданным ключом, вывод всех значений с ключами в консоль,
поиск элементов по ключу. Для тестирования программы предусмотрите ввод данных и
команд из стандартной консоли: • add — добавить элемент с ключом; • remove —
удалить все элементы с заданным ключом; • print — напечатать на экране все
элементы с их ключами; • find — найти все элементы по их ключу. Данный словарь
должен работать на значениях и ключах следующих типов: int, double,
std::string.*/

#include <iostream>
#include <list>
#include <map>
#include <string>
#include <vector>

template <typename TKey, typename TValue> class Registry {
  std::map<TKey, std::list<TValue>> data;

public:
  void add(TKey key, TValue value) { data[key].push_back(value); }

  size_t remove(TKey key) { return data.erase(key); }

  void print(void) {
    for (const auto &[key, valueList] : data) {
      std::cout << key << ": ";
      for (const TValue &value : valueList)
        std::cout << value << ", ";
      std::cout << std::endl;
    }
  }

  std::vector<TValue> find(TKey key) {

    if (data.contains(key)) {
      return std::vector<TValue>(data[key].begin(), data[key].end());
    }

    return std::vector<TValue>();
  }
};

int main() {
  Registry<int, int> registy1;

  registy1.add(1, 1);
  registy1.add(1, 11);
  registy1.add(1, 111);
  registy1.add(1, 1111);

  registy1.add(2, 2);
  registy1.add(2, 22);
  registy1.add(2, 222);
  registy1.add(2, 2222);

  registy1.print();

  std::vector<int> v = registy1.find(1);

  for (int i : v)
    std::cout << i << " ";
  std::cout << std::endl;

  registy1.remove(1);
  registy1.print();

  Registry<std::string, double> registy2;

  registy2.add("str1", 1.1);
  registy2.add("str1", 11.11);
  registy2.add("str1", 111.111);
  registy2.add("str1", 1111.1111);

  registy2.add("str2", 2.2);
  registy2.add("str2", 22.22);
  registy2.add("str2", 222.222);
  registy2.add("str2", 2222.2222);

  registy2.print();

  std::vector<double> v2 = registy2.find("str2");

  for (double d : v2)
    std::cout << d << " ";
  std::cout << std::endl;

  registy2.remove("str2");
  registy2.print();

  return 0;
}
