/*Реализуйте простую симуляцию игры в рыбалку. В исходном текстовом файле реки
(river.txt) задаётся список из видов рыб, которые можно в ней поймать. Рыбок
может быть сколько угодно, разных видов. Виды при этом могут повторяться. В
начале программы пользователь указывает, какую именно рыбу он сейчас будет
ловить — вид этой рыбы. После этого из первого файла друг за другом
осуществляется чтение его содержимого, вид за видом. Если на отдельных шагах вид
совпал с указанным пользователем, в выходной файл basket.txt (корзинка)
записывается этот вид.
В конце программы показывается, сколько было поймано рыб за текущую ловлю.
Программу можно запускать несколько раз, при этом уже пойманные рыбы должны
сохраняться в файле-корзинке.*/

#include <fstream>
#include <iostream>
#include <string>

int main() {
  std::string catchingFish;
  std::cout << "What fish are we going to catch? ";
  std::cin >> catchingFish;

  std::ifstream riverFile("river.txt");
  std::ofstream basketFile("basket.txt", std::ios::app);
  if (riverFile.is_open() && basketFile.is_open()) {
    int counter = 0;
    while (!(riverFile.eof())) {
      std::string fish;
      riverFile >> fish;
      if (fish == catchingFish) {
        basketFile << fish << std::endl;
        counter++;
      }
    }

    std::cout << "Fish caught: " << counter << std::endl;

    riverFile.close();
    basketFile.close();
  } else {
    std::cout << "Failed to open file" << std::endl;
  }
}