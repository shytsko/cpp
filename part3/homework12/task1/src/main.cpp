#include <cpr/cpr.h>
#include <iostream>
#include <string>

void printResponse(cpr::Response &response) {
  std::cout << response.url << std::endl;
  std::cout << response.status_code << std::endl;
  std::cout << response.header["content-type"] << std::endl;
  std::cout << response.text << std::endl;
}

int main() {
  std::string baseURL = "http://httpbin.org";

  while (true) {
    std::string command;
    std::cout
        << "Enter request type (get, post, put, delete, patch) or exit > ";
    std::cin >> command;

    if (command == "exit")
      break;

    cpr::Response response;
    if (command == "get") {
      response = cpr::Get(cpr::Url{baseURL + "/get"});
    } else if (command == "post") {
      response = cpr::Post(cpr::Url{baseURL + "/post"});
    } else if (command == "put") {
      response = cpr::Put(cpr::Url{baseURL + "/put"});
    } else if (command == "delete") {
      response = cpr::Delete(cpr::Url{baseURL + "/delete"});
    } else if (command == "patch") {
      response = cpr::Patch(cpr::Url{baseURL + "/patch"});
    } else {
      std::cout << "Invalid command" << std::endl;
      continue;
    }

    printResponse(response);
  }

  return 0;
}
