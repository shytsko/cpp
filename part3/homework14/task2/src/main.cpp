/*Сделайте запрос к сервису httpbin.org, отправив при этом несколько
дополнительных аргументов с данными. Все названия аргументов и их значения
строковые и принимаются от пользователя. Пользователь последовательно вводит их
названия вместе со значениями, пока не встретится аргумент с названием “post”
или “get”, что будет означать, что ввод аргументов закончен и требуется
отправить их на сервер выбранным способом. Если пользователь выбрал “post”, то
выполняется POST-запрос и аргументы отправляются POST-способом (как форма). Если
“get”, то выполняется GET-запрос с GET-аргументами (прямо в URL). По результатам
выполнения запроса выведите ответ сервера в стандартную консоль и обратите
внимание на поля form или args, в зависимости от типа запроса в которых должны
быть перечислены все введённые вами аргументы*/

#include <cpr/cpr.h>
#include <iostream>
#include <list>
#include <map>
#include <string>
#include <fstream>
#include <nlohmann/json.hpp>

#ifdef _WIN32
#include <windows.h>
#endif

#define API_KEY ""

using json = nlohmann::json;

int main()
{
#ifdef _WIN32
  SetConsoleOutputCP(CP_UTF8);
#endif

  std::string baseURL = "https://api.kinopoisk.dev";
  cpr::Header header{{"accept", "application/json"}, {"X-API-KEY", API_KEY}};

  cpr::Response response;

  cpr::Parameters parameters;
  parameters.Add({"page", "2"});
  parameters.Add({"limit", "10"});
  parameters.Add({"selectFields", "id"});
  parameters.Add({"selectFields", "name"});
  parameters.Add({"selectFields", "enName"});

  response = cpr::Get(cpr::Url{baseURL + "/v1.4/movie"}, parameters, header);

  std::cout << response.url << std::endl;

  // std::ofstream file("data.json");
  // file << response.text;
  // file.close();

  // std::ifstream f("data.json");
  json data = json::parse(response.text);
  // f.close();

  std::cout << data.dump(4) << std::endl;
  std::cout << "выпыппыппвкерврпвашдбпдлр" << std::endl;

  return 0;
}
