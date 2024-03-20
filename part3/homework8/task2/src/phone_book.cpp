#include "phone_book.h"
#include "phone_number.h"
#include <map>

bool PhoneBook::add(const std::string &name, const std::string &phoneNumber) {
  if (PhoneNumber::isValidPhoneNumber(phoneNumber)) {
    data[name] = new PhoneNumber(phoneNumber);
    return true;
  }

  return false;
}

PhoneNumber *PhoneBook::findPnoneNumberByName(const std::string &name) {
  return data.count(name) ? data[name] : nullptr;
}

PhoneBook::~PhoneBook() {
  while (!data.empty()) {
    auto iter = data.begin();
    PhoneNumber *deletedNumber = iter->second;
    data.erase(iter->first);
    delete deletedNumber;
  }
}