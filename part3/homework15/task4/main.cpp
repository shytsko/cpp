/*Реализуйте шаблонную функцию подсчёта среднего арифметического числа в массиве
скалярных чисел произвольного типа. Это может быть int, double, float и так
далее. Ввод данных массива и вывод результата производится через стандартную
консоль.*/

#include <iostream>
#include <string>

#define SIZE 10

template <typename T> T avg(const T *values) {
  T sum = T(0);

  for (size_t i = 0; i < SIZE; i++)
    sum += values[i];

  return sum / (T)SIZE;
}

template <typename T> void input(T *values) {
  for (size_t i = 0; i < SIZE; i++)
    std::cin >> values[i];
}

int main() {
  int intValues[SIZE];

  std::cout << "Enter " << SIZE << " integer values > ";
  input(intValues);
  std::cout << "Average: " << avg(intValues) << std::endl;

  double doubleValues[SIZE];
  std::cout << "Enter " << SIZE << " real values > ";
  input(doubleValues);
  std::cout << "Average: " << avg(doubleValues) << std::endl;

  return 0;
}
