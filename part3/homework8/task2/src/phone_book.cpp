#include "phone_book.h"
#include "phone_number.h"
#include <map>

// Добавление нового контакта
bool PhoneBook::add(const std::string &name, const std::string &phoneNumber)
{
  if (PhoneNumber::isValidPhoneNumber(phoneNumber))
  {
    // Если контакт с таким именем существует, нужно удалить объект
    if (data.count(name))
      delete data[name];
    data[name] = new PhoneNumber(phoneNumber);
    return true;
  }

  return false;
}

// Проверка , есть ли в справочнике контакт с таким именем
PhoneNumber *PhoneBook::findPnoneNumberByName(const std::string &name)
{
  return data.count(name) ? data[name] : nullptr;
}

PhoneBook::~PhoneBook()
{
  // Удаляем все динамически созданные объекты перед уничтожением справочника
  while (!data.empty())
  {
    auto iter = data.begin();
    PhoneNumber *deletedNumber = iter->second;
    data.erase(iter->first);
    delete deletedNumber;
  }
}