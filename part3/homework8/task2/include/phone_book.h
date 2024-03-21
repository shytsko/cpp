#pragma once
#include "phone_number.h"
#include <map>
#include <string>

class PhoneBook {
  std::map<std::string, PhoneNumber *> data;

public:
  bool add(const std::string &name, const std::string &phoneNumber);
  PhoneNumber *findPnoneNumberByName(const std::string &name);
  ~PhoneBook();
};
