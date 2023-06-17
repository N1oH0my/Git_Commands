#include "HashTable_1.h"

HashTable_1::HashTable_1(size_t maxSize) : maxSize(maxSize)
{
    table.resize(maxSize);
}

void HashTable_1::fill(std::ifstream& file)
{
    std::string key, value;
    while (file >> key >> value) 
        insert(std::make_pair(key, value));
}

size_t HashTable_1::hash(std::string key)
{
    size_t summ = 0;

    for (auto& symb : key)
        summ += symb;

    return summ % maxSize;
}
void HashTable_1::insert(std::pair<std::string, std::string> pair)
{
    bool isFind = false;
    size_t position = hash(pair.first);

    if (std::find(table[position].begin(), table[position].end(), pair) == table[position].end())
        table[position].push_back(pair);
}

bool HashTable_1::erase(std::string key)
{
    bool isFind = true;
    size_t position = hash(key);
    std::list<std::pair<std::string, std::string>>::iterator it =
        std::find_if(table[position].begin(), table[position].end(), [key](std::pair<std::string, std::string> x) {return x.first == key; });

    if (it == table[position].end())
        isFind = false;
    else table[position].erase(it);

    return isFind;
}

bool HashTable_1::find(std::string key, std::pair<std::string, std::string>& pair)
{
    bool isFind = true;
    size_t position = hash(key);
    std::list<std::pair<std::string, std::string>>::iterator it =
        std::find_if(table[position].begin(), table[position].end(), [key](std::pair<std::string, std::string> x) {return x.first == key; });

    if (it == table[position].end())
        isFind = false;
    else pair = *it;

    return isFind;
}

void HashTable_1::view()
{
    for (auto& itVector : table)
        for (auto& itList : itVector)
            std::cout << itList.first << " - " << itList.second << '\n';
}