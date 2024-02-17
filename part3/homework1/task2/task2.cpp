/*Разработайте простейший просмотрщик текстовых файлов. В начале программы
 * пользователь вводит путь к текстовому файлу, который требуется открыть и
 * просмотреть. Внутренности файла необходимо вывести в стандартный вывод.
 * Программа должна работать для любых текстовых файлов в формате TXT, но вы
 * можете создать и свой отдельный файл для теста. Главное, чтобы файл был
 * англоязычным, дабы избежать проблем с кодировками.*/

#include <fstream>
#include <ios>
#include <iostream>
#include <string>

void viewFile(std::string filePath) {

  std::ifstream file(filePath, std::ios::binary);

  if (file.is_open()) {
    char buffer[21];
    while (!(file.eof())) {
      file.read(buffer, 20);
      buffer[file.gcount()] = '\0';
      std::cout << buffer;
    }
    file.close();
  }
}

int main() {
  std::string filePath;

  std::cout << "Enter file path: ";
  std::cin >> filePath;
  viewFile(filePath);
}