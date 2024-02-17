/*Разработайте программу, которая получает на вход, в стандартный ввод, путь к
файлу. На выходе программа должна определить, является ли данный файл
PNG-изображением. Данная процедура не просто должна смотреть на расширение
файла, но и произвести минимальный анализ его внутренностей, в бинарном режиме.
Внутренности валидного бинарного файла начинаются со специального 8-байтового
заголовка. Нас будут интересовать первые четыре байта. Первый байт всегда имеет
значение −119 (число со знаком минус), а следующие — это просто символы ‘P’,
‘N’, ‘G’, расположенные друг за другом. Обратите внимание, что все они в верхнем
регистре. По результатам проверки пути и внутренностей требуется сообщить
пользователю о результате проверки в стандартный вывод.*/

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>

std::string getExtension(std::string filePath) {
  size_t dotPosition = filePath.rfind('.');
  if (dotPosition == std::string::npos)
    return "";
  else {
    std::string extension = filePath.substr(dotPosition + 1);
    std::transform(extension.begin(), extension.end(), extension.begin(),
                   [](unsigned char c) { return std::tolower(c); });
    return extension;
  }
}

bool isPngFile(std::string filePath) {
  std::string extension = getExtension(filePath);

  if (extension != "png")
    return false;

  std::ifstream file(filePath, std::ios::binary);

  if (file.is_open()) {
    char buffer[4];
    file.read(buffer, 4);
    file.close();
    return buffer[0] == -119 && buffer[1] == 'P' && buffer[2] == 'N' &&
           buffer[3] == 'G';
  }
  return false;
}

int main() {
  std::string filePath;

  std::cout << "Enter file path: ";
  std::cin >> filePath;
  if (isPngFile(filePath)) {
    std::cout << "File " << filePath << " is PNG format file";
  } else {
    std::cout << "File " << filePath << " is no PNG format file";
  }
}