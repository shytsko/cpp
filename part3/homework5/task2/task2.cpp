/*Используя макросы вместе с условными директивами прекомпиляции (#if / #endif),
реализуйте простую программу по выводу названия времени года в консоль.
Пользователь программы, который будет иметь дело с вашим кодом, в этом случае
тоже программист. С помощью определения одного из макросов (в самом коде):
SPRING, SUMMER, AUTUMN или WINTER он задаёт сезон, название, которое хочет
увидеть на экране. При компиляции и запуске программы на экране должно появиться
название именно этого сезона и только его.*/
#include <iostream>

// #define SPRING
// #define SUMMER
// #define AUTUMN
// #define WINTER

// Определение в параметрах при компиляции
//  g++ -D WINTER task2.cpp -o task2.exe

int main() {
#ifdef SPRING

  std::cout << "Spring";

#elif defined SUMMER

  std::cout << "Summer";

#elif defined AUTUMN

  {
    std::cout << "Autumn";

#elif defined WINTER

  std::cout << "Winter";

#else

  std::cout << "The time of year is uncertain";

#endif
}