/*Реализуйте простую и безопасную модель работы корзины онлайн-магазина.
• В начале программы вы заполняете базу данных самого магазина через стандартную
консоль. Каждый элемент этой базы данных состоит из двух компонентов — артикула
и количества штук. • Корзина должна поддерживать следующие операции: добавление
товара с указанным его количеством — add, удаление товара с указанным
количеством — remove. Обе операции принимают артикул товара в виде строки и
количество в виде целого числа. • При вводе аргументов к операциям должна
осуществляться их валидация. Артикул должен быть в базе данных магазина,
количество не должно превышать количество доступного продукта на складе (при
удалении — в корзине).*/

#include <exception>
#include <iostream>
#include <map>
#include <sstream>
#include <stdexcept>

// Базовый класс для хранилища. Логика работы склада и корзины идентичная
class Container {
  // Объект для хранения. Ключ - артикул товара, значение - количество
  std::map<std::string, int> storage;

protected:
  // Приватный конструктор, чтобы нельзя было создать объект этого класса
  Container() {}

public:
  // Поместить товар в хранилище
  void put(std::string partnumber, int quantity) {
    if (quantity < 0)
      throw std::invalid_argument("Quantity cannot be less than 0.");

    storage[partnumber] += quantity;
  }

  // Взять товар из хранилища
  void take(std::string partnumber, int quantity) {

    // Проверка, есть ли товар с таким артикулом
    if (!storage.contains(partnumber))
      throw std::invalid_argument("There is no product with this partnumber");

    // Проверка, не передано ли отрицательное количество
    if (quantity < 0)
      throw std::invalid_argument("Quantity cannot be less than 0.");

    // Проверка на доступное количество
    if (quantity > storage[partnumber])
      throw std::invalid_argument(
          "Quantity requested is greater than available");

    storage[partnumber] -= quantity;

    // Если товар закончился, он удаляется из словаря
    if (storage[partnumber] == 0)
      storage.erase(partnumber);
  }

  int getQuantity(std::string partnumber) {
    if (!storage.contains(partnumber))
      throw std::invalid_argument(
          "There is no product with this article number");

    return storage[partnumber];
  }

  // Перемещение товара
  void move(Container &destination, const std::string &partnumber,
            int quantity) {
    take(partnumber, quantity);
    destination.put(partnumber, quantity);
  }

  std::string view() {
    if (storage.empty())
      return "(Empty)\n";

    std::stringstream ss;
    for (const auto &[partnumber, quantity] : storage)
      ss << partnumber << ":\t" << quantity << std::endl;
    return ss.str();
  }
};

class Stock : public Container {
public:
  std::string view() {
    return "------------ STOCK -------------\n" + Container::view() +
           "-------------------------------\n";
  }
};

class Cart : public Container {
public:
  std::string view() {
    return "------------ CART -------------\n" + Container::view() +
           "-------------------------------\n";
  }
};

void executeCommand(Container &stock, Container &cart,
                    const std::string &command, const std::string &partnumber,
                    int quantity) {
  if (command == "add")
    stock.move(cart, partnumber, quantity);
  else if (command == "rm")
    cart.move(stock, partnumber, quantity);
  else
    throw std::invalid_argument("Invalid command");
}

int main() {

  Cart cart;
  Stock stock;

  for (int i = 1; i <= 5; i++)
    stock.put("pr" + std::to_string(i), i * 10);

  std::string command;
  std::string partnumber;
  int quantity;

  while (true) {
    std::cout << stock.view() << std::endl;
    std::cout << cart.view() << std::endl;

    std::cout << "Enter command (add or rm), partnumber and quantity > ";
    std::cin >> command;
    if (command == "exit")
      break;

    std::cin >> partnumber >> quantity;

    try {
      executeCommand(stock, cart, command, partnumber, quantity);
    } catch (const std::invalid_argument &ex) {
      std::cerr << ex.what() << std::endl;
    }
  }

  return 0;
}
