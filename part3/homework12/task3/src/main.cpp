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

int main() {
  std::map<std::string, std::string> arguments;

  std::string key, value;
  while (true) {
    std::cout << "Enter the name of the argument or get or post to send the "
                 "request > ";
    std::cin >> key;
    if (key == "get" || key == "post")
      break;

    std::string value;
    std::cout << "Enter value > ";
    std::cin >> value;

    arguments[key] = value;
  }

  cpr::Response response;

  if (key == "get") {
    cpr::Parameters parameters;
    for (auto pair : arguments)
      parameters.Add({pair.first, pair.second});
    response = cpr::Get(cpr::Url{"http://httpbin.org/get"}, parameters);
  } else {
    std::list<cpr::Pair> pairs;
    for (auto pair : arguments)
      pairs.push_back({pair.first, pair.second});

    cpr::Payload payload(pairs.begin(), pairs.end());
    response = cpr::Post(cpr::Url{"http://httpbin.org/post"}, payload);
  }

  std::cout << response.text << std::endl;

  return 0;
}
