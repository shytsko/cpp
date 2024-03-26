/*Требуется реализовать упрощённую модель работы кухни ресторана, работающего в
режиме онлайн-доставки. Онлайн-заказ поступает каждые 5–10 секунд. Это случайное
блюдо из пяти: пицца, суп, стейк, салат, суши. Официант, принявший заказ онлайн,
оставляет его у кухни. Если кухня свободна, она принимает заказ и спустя 5–15
секунд возвращает уже готовое блюдо на выдачу. Время определяется случайным
образом с помощью функции std::rand() в указанных диапазонах. Курьер приезжает
каждые 30 секунд, забирает готовые блюда на выдаче и развозит их по заказчикам.
Программа завершается после 10 успешных доставок. На каждом из этапов, будь то
заказ, или готовка, или доставка заказа, выводятся соответствующие сообщения в
консоль.*/

#include <atomic>
#include <iostream>
#include <mutex>
#include <queue>
#include <string>
#include <thread>
#include <vector>

const std::vector<std::string> dishes = {"pizza", "soup", "steak", "salad",
                                         "sushi"};

struct Order {
  int id;
  std::string dish;
};

std::queue<Order> orderQueue;
std::mutex orderQueueLock;

std::queue<Order> deliveryQueue;
std::mutex deliveryQueueLock;

std::mutex outputLock;

void waiter(void) {
  int newOrderID = 0;

  while (true) {
    std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 6 + 5));
    Order order{++newOrderID, dishes[(size_t)std::rand() % dishes.size()]};

    orderQueueLock.lock();
    orderQueue.push(order);
    orderQueueLock.unlock();

    outputLock.lock();
    std::cout << "The order (" << order.id << ": " << order.dish
              << ") has been accepted and is awaiting cooking." << std::endl;
    outputLock.unlock();
  }
}

void chef(void) {
  while (true) {
    while (orderQueue.empty())
      std::this_thread::yield();

    orderQueueLock.lock();
    Order order = orderQueue.front();
    orderQueue.pop();
    orderQueueLock.unlock();

    outputLock.lock();
    std::cout << "The order (" << order.id << ": " << order.dish
              << ") has started to be cooking." << std::endl;
    outputLock.unlock();

    std::this_thread::sleep_for(std::chrono::seconds(std::rand() % 11 + 5));

    deliveryQueueLock.lock();
    deliveryQueue.push(order);
    deliveryQueueLock.unlock();

    outputLock.lock();
    std::cout << "The order (" << order.id << ": " << order.dish
              << ") is ready and submitted for delivery." << std::endl;
    outputLock.unlock();
  }
}

void courier(void) {
  int deliveryCounter = 0;

  while (deliveryCounter < 10) {
    std::this_thread::sleep_for(std::chrono::seconds(30));

    while (deliveryQueue.empty())
      std::this_thread::yield();

    deliveryQueueLock.lock();
    Order order = deliveryQueue.front();
    deliveryQueue.pop();
    deliveryQueueLock.unlock();

    outputLock.lock();
    std::cout << "The order (" << order.id << ": " << order.dish
              << ") delivered." << std::endl;
    outputLock.unlock();

    deliveryCounter++;
  }
}

int main() {
  std::thread waiterThread(waiter);

  std::thread chefThread(chef);

  std::thread courierThread(courier);

  waiterThread.detach();
  chefThread.detach();
  courierThread.join();

  return 0;
}
