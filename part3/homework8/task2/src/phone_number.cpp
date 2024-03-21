#include "phone_number.h"
#include <algorithm>
#include <string>

PhoneNumber::PhoneNumber(const std::string &strNumber)
{
  number = isValidPhoneNumber(strNumber) ? strNumber : "+70000000000";
}

const std::string &PhoneNumber::getPhoneNumber(void) { return number; }

// провека на валидность строки с номером телефона: строка не пустая, имеет длину 12 символов,
// начинается с +7, все остальные символы - цифры
bool PhoneNumber::isValidPhoneNumber(const std::string &strNumber)
{
  return !strNumber.empty() && strNumber.length() == 12 && strNumber.substr(0, 2) == "+7" &&
         std::find_if(strNumber.begin() + 2, strNumber.end(),
                      [](unsigned char c)
                      { return !std::isdigit(c); }) ==
             strNumber.end();
}

std::ostream &operator<<(std::ostream &out, const PhoneNumber &phoneNumber)
{
  out << phoneNumber.number;
  return out;
}