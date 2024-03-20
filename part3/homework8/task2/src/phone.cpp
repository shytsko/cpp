#include "phone.h"
#include "phone_number.h"
#include <iostream>
#include <string>

void Phone::addContact(void) {
  std::cout << "Enter name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Enter phone number: ";
  std::string phoneNumber;
  std::cin >> phoneNumber;
  phoneBook.add(name, phoneNumber);
}
void Phone::call(void) {
  std::cout << "Enter name or phone number: ";
  std::string input;
  std::cin >> input;
  PhoneNumber *phoneNumber = phoneBook.findPnoneNumberByName(input);
  if (phoneNumber)
    std::cout << "CALL " << *phoneNumber << std::endl;
  else if (PhoneNumber::isValidPhoneNumber(input))
    std::cout << "CALL " << input << std::endl;
  else
    std::cout << "Incorrect phone number or contact name" << std::endl;
}
void Phone::sms(void) {}