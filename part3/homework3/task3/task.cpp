/*
Реализуйте структуру двумерного математического вектора и основные операции над
ним. Обе координаты вектора (x и y) должны быть вещественными числами. Начиная
работу с программой, пользователь вводит команду. Затем в зависимости от команды
пользователь вводит аргументы. Это могут быть как векторы, так и обычные
скалярные значения. Результат помещается в стандартный вывод. Это тоже может
быть или вектор, или скаляр.

Реализуйте в виде отдельных функций операции:
• сложение двух векторов — команда add;
• вычитание двух векторов — команда subtract;
• умножение вектора на скаляр — команда scale;
• нахождение длины вектора — команда length;
• нормализация вектора — команда normalize.
*/

#include <cmath>
#include <iostream>
#include <istream>
#include <sstream>
#include <string>

struct Vector {
  float x = 0.0f;
  float y = 0.0f;
};

Vector operator+(const Vector &vectorA, const Vector &vectorB) {
  Vector resultVector = {vectorA.x + vectorB.x, vectorA.y + vectorB.y};
  return resultVector;
}

Vector operator-(const Vector &vectorA, const Vector &vectorB) {
  Vector resultVector = {vectorA.x - vectorB.x, vectorA.y - vectorB.y};
  return resultVector;
}

Vector operator*(const Vector &vector, const float &scale) {
  Vector resultVector = {vector.x * scale, vector.y * scale};
  return resultVector;
}

float length(Vector vector) {
  return (float)std::sqrt(std::pow(vector.x, 2) + std::pow(vector.y, 2));
}

Vector normalize(Vector vector) {
  Vector c = vector * (1.0f / length(vector));
  return c;
}

std::string vectorToString(Vector vector) {
  std::stringstream ss;
  ss << "Vector(" << vector.x << "; " << vector.y << ")";
  return ss.str();
}

Vector readVector() {
  Vector vector;
  std::cin >> vector.x >> vector.y;
  return vector;
}

int main() {
  std::cout << "Command:" << std::endl
            << "add - addition of two vectors" << std::endl
            << "sub - subtraction vectors" << std::endl
            << "scl - scalar product of a vector and a number" << std::endl
            << "len - calculate vector length" << std::endl
            << "norm - get normalized vector" << std::endl
            << "> ";

  std::string command;
  std::cin >> command;

  if (command == "add") {
    std::cout << "Enter first vector: ";
    Vector vectorA = readVector();
    std::cout << "Enter second vector: ";
    Vector vectorB = readVector();
    Vector sumVector = vectorA + vectorB;
    std::cout << vectorToString(vectorA) << " + " << vectorToString(vectorB)
              << " = " << vectorToString(sumVector) << std::endl;
  } else if (command == "sub") {
    std::cout << "Enter first vector: ";
    Vector vectorA = readVector();
    std::cout << "Enter second vector: ";
    Vector vectorB = readVector();
    Vector subVector = vectorA - vectorB;
    std::cout << vectorToString(vectorA) << " - " << vectorToString(vectorB)
              << " = " << vectorToString(subVector) << std::endl;
  } else if (command == "scl") {
    std::cout << "Enter vector: ";
    Vector vector = readVector();
    std::cout << "Enter scalar value: ";
    float scalar;
    std::cin >> scalar;
    Vector scaleVector = vector * scalar;

    std::cout << vectorToString(vector) << " * " << scalar << " = "
              << vectorToString(scaleVector) << std::endl;
  } else if (command == "len") {
    std::cout << "Enter vector: ";
    Vector vector = readVector();
    float len = length(vector);
    std::cout << "Length " << len << std::endl;
  } else if (command == "norm") {
    std::cout << "Enter vector: ";
    Vector vector = readVector();
    Vector normVector = normalize(vector);
    std::cout << "Normalized vector" << vectorToString(normVector) << std::endl;
  } else {
    std::cout << "Invalid command" << std::endl;
  }
}