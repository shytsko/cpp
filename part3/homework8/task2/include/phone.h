#pragma once
#include "phone_book.h"
#include "phone_number.h"

class Phone
{
  PhoneBook phoneBook;

  std::string selectСontact(void);

public:
  void addContact(void);
  void call(void);
  void sms(void);
};