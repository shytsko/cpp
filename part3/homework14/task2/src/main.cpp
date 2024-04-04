// https://kinopoisk.dev/documentation

#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

#define API_KEY "3ZVX2RC-JE54VS4-KWQZ27E-NCP91EA"

using json = nlohmann::json;

int main() {
  std::string baseAPIURL = "https://api.kinopoisk.dev";
  cpr::Header header{{"accept", "application/json"}, {"X-API-KEY", API_KEY}};

  cpr::Response response;

  std::string name;
  std::cout << "Enter name > ";
  std::getline(std::cin, name);
  json data;
  int nextPage = 0;

  std::cout << "Matches found: " << std::endl;
  do {
    response = cpr::Get(cpr::Url{baseAPIURL + "/v1.4/person/search"},
                        cpr::Parameters{{"query", name},
                                        {"page", std::to_string(++nextPage)},
                                        {"limit", "250"}},
                        header);
    std::cout << response.url;

    if (response.status_code != 200) {
      std::cout << "Error" << std::endl << response.text << std::endl;
      exit(-1);
    }
    data = json::parse(response.text);

    for (const auto &person : data["docs"]) {
      if (person["name"] == name || person["enName"] == name) {
        std::cout << person["id"] << ": " << person["enName"] << std::endl;
      }
    }
  } while (nextPage < data["pages"]);

  // if (data["total"] != 0) {
  //   std::cout << "Actor found: " << data["docs"][0]["enName"] << std::endl;
  //   std::cout << "Starred in films:" << std::endl;
  //   int id = data["docs"][0]["id"];
  //   response = cpr::Get(
  //       cpr::Url{baseAPIURL + "/v1.4/person/" + std::to_string(id)}, header);
  //   data = json::parse(response.text);
  //   for (const auto &movie : data["movies"])
  //     if (movie["enProfession"] == "actor")
  //       std::cout << movie["alternativeName"] << " as " <<
  //       movie["description"]
  //                 << std::endl;
  // } else {
  //   std::cout << "Actor not found" << std::endl;
  // }

  return 0;
}
