// https://kinopoisk.dev/documentation

#include <cpr/cpr.h>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <set>

// Здесь должен быть указан ключ API. Можно задать также в параметрах компиляции в коммандной строке или в конфигкрации CMake
#ifndef API_KEY
#define API_KEY ""
#endif

using json = nlohmann::json;

int main()
{
  std::string baseAPIURL = "https://api.kinopoisk.dev";
  cpr::Header header{{"accept", "application/json"}, {"X-API-KEY", API_KEY}};

  cpr::Response response;

  std::string name;
  std::cout << "Enter name > ";
  std::getline(std::cin, name);

  // Поиск по имени. Имя актера должно совпадать с именем на портеле https://www.kinopoisk.ru/
  // name берем в кавычки, чтобы в результ попали только строгие соответствия,
  // иначе будут включены похожие записи и результатов будет очень много
  // Также считаем, что лимит в 100 записей достаточно, чтобы получить все результаты с одного запроса и
  // пагинацию не учитываем
  response = cpr::Get(cpr::Url{baseAPIURL + "/v1.4/person/search"},
                      cpr::Parameters{{"query", "\"" + name + "\""},
                                      {"limit", "100"}},
                      header);

  if (response.status_code != 200)
  {
    std::cout << "Error" << std::endl
              << response.text << std::endl;
    exit(-1);
  }

  json data = json::parse(response.text);

  if (data["total"] == 0)
  {
    std::cout << "No results found" << std::endl;
    return 0;
  }

  unsigned long detailID = 0;

  if (data["total"] == 1)
  {
    std::cout << "One actor found:" << std::endl
              << std::endl;

    // Если результат поиска только один, устанавливаем его идентификатор для получения списка фильмов
    detailID = data["docs"][0]["id"];
  }
  else
    std::cout << "Several actors with this name have been found:" << std::endl
              << std::endl;

  std::set<unsigned long> validID;
  for (auto &person : data["docs"])
  {
    std::cout << "id: " << person["id"] << std::endl
              << "name: " << person["enName"] << std::endl
              << "photo: " << person["photo"] << std::endl
              << std::endl;
    validID.insert(person["id"].get<unsigned long>());
  }

  // Если результатов поиска несколько, дополнительно запрашиваем, по какому конкретно id получать список фильмов
  if (detailID == 0)
  {
    while (true)
    {
      std::cout << "Enter actor ID to display detailed information > ";
      std::cin >> detailID;
      if (validID.contains(detailID))
        break;
    }
  }

  response = cpr::Get(
      cpr::Url{baseAPIURL + "/v1.4/person/" + std::to_string(detailID)}, header);

  data = json::parse(response.text);

  // Выводим только те записи, в которых актер принимал участие как актер. В поле "description" указана роль
  for (const auto &movie : data["movies"])
    if (movie["enProfession"] == "actor")
      std::cout << movie["alternativeName"] << " as " << movie["description"]
                << std::endl;

  return 0;
}
