/*В поезде всего 10 вагонов. В каждом из этих вагонов может находиться до 20
пассажиров — это их оптимальное количество. Проанализируйте количество людей в
каждом вагоне и сначала сообщите об излишне заполненных вагонах, далее о вагонах
с пустыми пассажирскими местами. В заключение выведите общее количество
пассажиров во всех вагонах. При старте программы пользователь вводит количество
пассажиров в каждом вагоне. Замечания о вагонах должны выводиться в стандартную
консоль. При выполнении задания пользоваться нельзя напрямую пользоваться
for-циклами, только опосредованно, через макросы.
*/

#include <iostream>

#define OPTIMAL_NUMBER_PASSENGERS 20
#define NUMBER_CARRIAGES 10

// вызов функции FUNC для каждого элемента массива ARR
// функция FUNC должна принимать два параметра: номер вагона и количство пассажиров в нем
#define CALL_FOR_EACH(ARR, FUNC)                  \
  for (unsigned i = 0; i < NUMBER_CARRIAGES; i++) \
    FUNC((i + 1), ARR[i]);

// Функция выводит сообщение, если вагон перегружен
void checkOverflowing(unsigned number, unsigned passengerCount)
{
  if (passengerCount > OPTIMAL_NUMBER_PASSENGERS)
    std::cout << "Carriage number " << number << " overflowing" << std::endl;
}

// Функция выводит сообщение, если в вагоне есть свободные места
void checkEmptyPlaces(unsigned number, unsigned passengerCount)
{
  if (passengerCount < OPTIMAL_NUMBER_PASSENGERS)
    std::cout << "In Carriage number " << number
              << " there are free empty seats" << std::endl;
}

// Функция подсчитывает общее количество пассажиров.
void totalPassengers(unsigned number, unsigned passengerCount)
{
  static unsigned total = 0;
  if (number == 1)
    total = 0;

  total += passengerCount;

  if (number == NUMBER_CARRIAGES)
    std::cout << "Total number of passengers: " << total << std::endl;
}

int main()
{
  unsigned carriages[NUMBER_CARRIAGES] = {10, 15, 20, 22, 14,
                                          25, 19, 20, 18, 20};

  CALL_FOR_EACH(carriages, checkOverflowing)
  CALL_FOR_EACH(carriages, checkEmptyPlaces)
  CALL_FOR_EACH(carriages, totalPassengers)

  return 0;
}
