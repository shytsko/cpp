#pragma once
#include <string>

class PhoneNumber {
  std::string number = "+70000000000";

public:
  PhoneNumber(const std::string &strNumber);
  const std::string &getPhoneNumber(void);
  static bool isValidPhoneNumber(const std::string &strNumber);
  friend std::ostream &operator<<(std::ostream &out,
                                  const PhoneNumber &phoneNumber);
};