/*Напишите функцию, которая принимает две строки и возвращает true, если первая
строка является анаграммой второй (то есть можно получить первую строку из
второй путём перестановки букв местами), и false иначе. Для достижения хорошей
асимптотики решения рекомендуется использовать std::map. Пример анаграммы:
лекарство — стекловар*/

#include <iostream>
#include <map>
#include <string>

bool isAnagram(std::string text1, std::string text2)
{
  // Если длины строк не равны, дальше можно не проверять
  if (text1.length() != text2.length())
    return false;

  std::map<char, int> chars;

  // Подсчет разности количества каждого символа в строках
  // В анаграмме количество каждого символа в двух строках должно быть
  // одинаковым и итоге все занчения в словаре должны быть равны 0
  for (size_t i = 0; i < text1.length(); i++)
  {
    chars[text1[i]]++;
    chars[text2[i]]--;
  }

  for (std::pair<const char, int> &p : chars)
    if (p.second != 0)
      return false;

  return true;
}

int main()
{
  std::string text1, text2;
  std::cout << "Enter first text\n> ";
  std::getline(std::cin, text1);
  std::cout << "Enter second text\n> ";
  std::getline(std::cin, text2);

  if (isAnagram(text1, text2))
    std::cout << "The texts are anograms" << std::endl;
  else
    std::cout << "Texts are not anograms" << std::endl;

  return 0;
}
