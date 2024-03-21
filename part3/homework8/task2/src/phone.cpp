#include "phone.h"
#include "phone_number.h"
#include <iostream>
#include <string>

void Phone::addContact(void)
{
  std::cout << "Enter name: ";
  std::string name;
  std::cin >> name;
  std::cout << "Enter phone number: ";
  std::string phoneNumber;
  std::cin >> phoneNumber;
  phoneBook.add(name, phoneNumber);
}

std::string Phone::selectСontact(void)
{
  std::cout << "Enter name or phone number: ";
  std::string input;
  std::cin >> input;
  PhoneNumber *phoneNumber = phoneBook.findPnoneNumberByName(input);
  if (phoneNumber)
    return phoneNumber->getPhoneNumber();
  else if (PhoneNumber::isValidPhoneNumber(input))
    return input;
  else
    return "";
}

void Phone::call(void)
{
  std::string number = selectСontact();
  if (number != "")
    std::cout << "Call to " << number << std::endl;
  else
    std::cout << "Bad number" << std::endl;
}

void Phone::sms(void)
{
  std::string number = selectСontact();
  if (number != "")
  {
    std::string message;
    std::cout << "Enter message: ";
    std::cin >> message;
    std::cout << "Send message " << message << " to " << number << std::endl;
  }
  else
  {
    std::cout << "Bad number" << std::endl;
  }
}