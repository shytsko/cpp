/* Реализуйте простую версию интеллектуальной игры «Что? Где? Когда?».
Как происходит игра
В начале каждого хода игроки вращают волчок, то есть выбирают сектор на столе,
который сейчас играет. Всего таких секторов 13. Сектор выбирается так: с
клавиатуры вводится офсет (смещение) относительно текущего сектора на барабане.
Исходя из этого офсета вычисляется новый активный сектор, который и будет играть
в этом ходе. Если выпавший сектор уже играл, выбирает следующий не игравший за
ним. В начале всей игры стрелка установлена на первом секторе.

Как только играет какой-то из секторов, с него берётся письмо с вопросом — то
есть считывается из файла данного сектора. Вопрос показывается на экране. После
того как вопрос показан, от игрока ожидается ответ на него. Игрок вводит этот
ответ с помощью стандартного ввода. То, что он ввёл, сравнивается с ответом,
который хранится во втором файле, ассоциированном с активным сектором. Данный
файл должен содержать лишь одно слово-ответ.

Если ответ знатока-игрока был правильным, ему начисляется один балл. Если
неверен, то балл уходит телезрителям. Игра продолжается до тех пор, пока или
игрок, или зрители не наберут шесть баллов. После этого называется победитель и
программа заканчивает работу.*/

#include <fstream>
#include <iostream>
#include <string>

int getNextSector(int currentSector) {
  static int usedSectors[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
  int steps;
  std::cin >> steps;
  int sector = (currentSector + steps - 1) % 13;
  while (usedSectors[sector])
    sector = (sector + 1) % 13;
  usedSectors[sector] = 1;
  return sector + 1;
}

std::string getQuestion(int sector) {
  std::string filePath = "data\\question" + std::to_string(sector) + ".txt";
  std::ifstream file(filePath, std::ios::binary);

  if (file.is_open()) {
    std::string question = "";
    char buffer[255];
    while (!(file.eof())) {
      file.read(buffer, 254);
      buffer[file.gcount()] = '\0';
      question += buffer;
    }
    file.close();
    return question;
  } else {
    return std::string("");
  }
}

std::string getAnswer(int sector) {
  std::string filePath = "data\\answer" + std::to_string(sector) + ".txt";
  std::ifstream file(filePath);

  if (file.is_open()) {
    std::string answer;
    file >> answer;
    file.close();
    return answer;
  } else {
    return std::string("");
  }
}

int main() {
  int scoresExperts = 0;
  int scoresTVViewers = 0;
  int sector = 1;

  while (scoresExperts < 6 && scoresTVViewers < 6) {
    std::cout << "Spin the top: ";
    sector = getNextSector(sector);
    std::cout << "Sector " << sector << std::endl;

    std::string question = getQuestion(sector);
    std::cout << question << std::endl;

    std::string answer;
    std::cout << "Your answer: ";
    std::cin >> answer;

    std::string trueAnswer = getAnswer(sector);

    if (answer == trueAnswer) {
      std::cout << "Answer is correct" << std::endl;
      scoresExperts++;
    } else {
      std::cout << "The answer is not correct. Correct answer: " << trueAnswer
                << std::endl;
      scoresTVViewers++;
    }

    std::cout << "Scores: " << scoresExperts << " : " << scoresTVViewers
              << std::endl;

    if (scoresExperts == 6) {
      std::cout << "Experts won!!!";
      break;
    } else if (scoresTVViewers == 6) {
      std::cout << "TV viewers won!!!";
      break;
    }
  }
}