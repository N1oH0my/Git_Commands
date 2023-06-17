#include "HashTable2.h"
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::ifstream file("data.txt");
    HashTable2 table(100);
    table.fill(file);
    
    table.insert(std::make_pair("elephant", "слон"));
    table.insert(std::make_pair("elephant", "слон"));
    table.view();

    std::cout << "\n--------------------\n";

    table.erase("fox");
    table.view();

    std::cout << "\n--------------------\n";

    table.insert(std::make_pair("fox", "лиса"));
    table.view();

    std::cout << "\n--------------------\n";

    std::pair<std::string, std::string> pr;
    table.find("elephant", pr);
    std::cout << pr.first << " - " << pr.second;

    std::cin.get();
    return 0;
}