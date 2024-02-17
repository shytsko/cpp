/*Составьте небольшой текстовый файл «words.txt», в котором последовательно,
через пробелы и переносы строк расположены различные слова. Можете использовать
любые англоязычные слова. Разработайте программу, которая искала бы среди этих
слов нужное пользователю и выводила бы общее количество повторений этого слова.
0 — если слово вообще не присутствует в файле.*/

#include <fstream>
#include <iostream>
#include <string>

int wordSearch(std::string filePath, std::string word) {
  std::ifstream file(filePath);

  int result = 0;

  if (file.is_open()) {
    std::string line;
    while (!(file.eof())) {
      std::getline(file, line);
      line = " " + line + " ";

      size_t startSearchPos = 0;
      size_t pos;
      while ((pos = line.find(word, startSearchPos)) != std::string::npos) {
        if ((line[pos - 1] == ' ' && (line[pos + word.length()] == ' ' ||
                                      line[pos + word.length()] == '\r'))) {
          result++;
        }
        startSearchPos = pos + word.length();
      }
    }

    file.close();
  }

  return result;
}

int main() {
  std::string word;
  std::cout << "Enter word for search: ";
  std::cin >> word;

  std::cout << "Found occurrences of the word: "
            << wordSearch("words.txt", word) << std::endl;
  return 0;
}
