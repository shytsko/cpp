// Вы уже создавали программу чтения и записи ведомости. Теперь её нужно
// обобщить и дополнить использованием структур. Формат ведомости прежний: •
// сначала — имя и фамилия получателя денег, • далее — дата выдачи в формате
// ДД.ММ.ГГГГ, • затем — сумма выплаты в рублях. Данные разделяются пробелами.
// В конце каждой записи должен быть перевод строки. Структура данных должна
// соответствовать этому формату.

// При старте программы пользователь отправляет команду: list или add. Команда
// list осуществляет чтение из файла ведомости, как и прежде, только уже в
// структуры данных, и отображает их на экране. Команда add добавляет новую
// запись в конец ведомости.

#include <cstddef>
#include <fstream>
#include <iostream>
#include <string>

struct Record
{
    std::string firstName;
    std::string lastName;
    std::string date;
    int salary;
};

bool validateDateFormat(std::string date)
{
    size_t dotFirst = date.find('.');
    size_t dotSecond = date.rfind('.');
    if (date.length() != 10 || dotFirst != 2 || dotSecond != 5)
        return false;

    int day = std::stoi(date.substr(0, 2));
    int month = std::stoi(date.substr(3, 2));

    if (day < 1 || day > 31)
        return false;

    if (month < 1 || month > 12)
        return false;

    return true;
}

void list(const std::string &filePath)
{
    std::ifstream file(filePath);

    if (file.is_open())
    {
        while (!(file.eof()))
        {
            Record record;
            file >> record.firstName >> record.lastName >> record.salary >> record.date;
            std::cout << record.firstName << ' ' << record.lastName << ' ' << record.date << ' ' << record.salary << std::endl;
        }
    }
    else
    {
        std::cout << "No file" << std::endl;
    }
}

void add(const std::string &filePath)
{
}

int main()
{
    std::string filePath = "salary.txt";
    std::string command;
    std::cout << "Command\nlist - print all record\nadd - add new record\n> ";
    std::cin >> command;

    if (command == "list")
    {
        list(filePath);
    }
    else if (command == "add")
    {
        add(filePath);
    }
    else
    {
        std::cout << "Not valid command" << std::endl;
    }
}
