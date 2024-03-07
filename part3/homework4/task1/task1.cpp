/* Напишите программу «Телефонный справочник».
На вход программе поступают запросы трёх типов:
69-70-30 Ivanov — добавить телефон и фамилию абонента в справочник
69-70-30 — узнать фамилию абонента по номеру телефона
Ivanov — узнать телефон абонента по фамилии
Необходимо выводить в консоль ответ на запросы 2 и 3. Обратите внимание, что
абоненты по разным номерам могут иметь одинаковые фамилии. В таком случае на
запрос 3 необходимо выдать все номера через пробелы. Операции запросов должны
работать за O(logn) или O(logn × количество номеров с этой фамилией).*/

#include <cstdio>
#include <iostream>
#include <map>
#include <string>
#include <vector>

struct PhoneBook
{
  std::map<std::string, std::string> nameByPhone;
  std::map<std::string, std::vector<std::string>> phoneByName;
};

int main()
{
  PhoneBook phoneBook;

  while (true)
  {
    std::cout << "Enter your request" << std::endl
              << "> ";
    std::string request;
    std::getline(std::cin, request);

    if (request == "exit")
      break;

    // Если во введенной строке есть сепаратор (пробел), строка разделяется на
    // телефон и имя и данные добавляются в два словаря
    size_t separatorPosition = request.find(' ');
    if (separatorPosition != std::string::npos)
    {
      std::string phone = request.substr(0, separatorPosition);
      std::string name = request.substr(separatorPosition + 1);
      phoneBook.nameByPhone[phone] = name;
      phoneBook.phoneByName[name].push_back(phone);
    }

    // Если введенная строка есть среди ключе словаря телефонов, выводится
    // связанное с номером имя
    else if (phoneBook.nameByPhone.count(request))
    {
      std::cout << phoneBook.nameByPhone[request] << std::endl;
    }

    // Если введенная строка есть среди ключей словаря имен, выводятся связанные
    // телефоны
    else if (phoneBook.phoneByName.count(request))
    {
      for (const std::string &phone : phoneBook.phoneByName[request])
        std::cout << phone << ' ';
      std::cout << std::endl;
    }
    else
    {
      std::cout << "Not found" << std::endl;
    }
  }

  return 0;
}