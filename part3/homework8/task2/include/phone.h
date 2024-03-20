#pragma once
#include "phone_book.h"
#include "phone_number.h"

class Phone {
  PhoneBook phoneBook;

public:
  void addContact(void);
  void call(void);
  void sms(void);
};