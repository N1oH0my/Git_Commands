#include "HashTable3.h"
#include <Windows.h>

int main()
{
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    std::ifstream file("data.txt");
    HashTable3 table(100);

    table.fill(file);
    table.view();

    std::cin.get();
    return 0;
}