/*Напишите функцию, которая принимает две строки и возвращает true, если первая
строка является анаграммой второй (то есть можно получить первую строку из
второй путём перестановки букв местами), и false иначе. Для достижения хорошей
асимптотики решения рекомендуется использовать std::map. Пример анаграммы:
лекарство — стекловар*/

#include <iostream>
#include <map>
#include <string>

bool isAnagram(std::string text1, std::string text2) {
  // Если длины строк не равны, дальше можно не проверять
  if (text1.length() != text2.length())
    return false;

  std::map<char, int> chars;

  // Подсчет количества каждого символа в первой строке
  for (char c : text1)
    chars[c]++;

  // Вычитание количество символов во второй строке
  for (char c : text2)
    chars[c]--;

  // Если в итоге значение по какому-либо ключу не равно 0, значит количество
  // этого символа не равно в обоих строках, а значит эти сторки не  являются
  // анаграммой
  for (std::pair<const char, int> &p : chars)
    if (p.second != 0)
      return false;

  return true;
}

int main() {
  std::string text1, text2;
  std::cout << "Enter first text\n> ";
  std::getline(std::cin, text1);
  std::cout << "Enter second text\n> ";
  std::getline(std::cin, text2);

  if (isAnagram(text1, text2))
    std::cout << "The texts are anograms" << std::endl;
  else
    std::cout << "Texts are not anograms" << std::endl;
}
