#include "HashTable_1.h"
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::ifstream file("data.txt");
    HashTable_1 table(100);

    std::string key, val;

    /*while (file >> key >> val)
        table.insert(std::make_pair(key, val));

    table.view();

    std::pair<std::string, std::string> pair;

    std::cout << (table.find("Fox", pair) ? pair.first + ' ' + pair.second : "");
    std::cout << "\n--------\n";
    table.erase("Fox");

    table.view();*/

    table.fill(file);
    table.view();

    std::pair<std::string, std::string> pair;
    table.find("fox", pair);
    std::cout << '\n' << pair.first << ' ' << pair.second;

    std::cout << "\n------------------------\n";

    table.insert(std::make_pair("fox", "лиса"));
    table.view();

    std::cout << "\n------------------------\n";

    if (table.erase("fox"))
        std::cout << "\nElem has been deleted.\n";
    else std::cout << "\nElem is not deleted.\n";

    std::cout << "\n------------------------\n";

    std::pair<std::string, std::string> pair1;
    if (table.find("rabbit", pair1))
        std::cout << pair1.second << '\n';
    else std::cout << "\nElem is not found\n";

    std::cout << "\n------------------------\n";

    table.view();

    std::cout << "\n------------------------\n";

    std::cin.get();
    return 0;
}