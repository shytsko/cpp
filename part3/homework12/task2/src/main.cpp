/*Запросите с сервера HTML-страницу. Для этого изучите документацию о запросах,
 * поддерживаемых сервисом httpbin.org/html. Найдите там запрос, который выдаёт
 * именно HTML-страницу. Затем сделайте запрос, явным образом используя
 * заголовок accept: text/html. В полученном ответе найдите заголовок статьи и
 * выведите его в консоль.*/

#include <cpr/cpr.h>
#include <iostream>
#include <string>

int main() {
  cpr::Response response = cpr::Get(cpr::Url{"http://httpbin.org/html"},
                                    cpr::Header{{"accept", "text/html"}});

  size_t begin = response.text.find("<h1>") + 4;
  size_t end = response.text.find("</h1>", begin);
  std::string title = response.text.substr(begin, end - begin);

  std::cout << title << std::endl;

  return 0;
}
