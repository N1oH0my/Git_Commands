#include "HashTable2.h"

HashTable2::HashTable2(size_t maxSize) : maxSize(maxSize)
{
    table.resize(maxSize);
}

void HashTable2::fill(std::ifstream& file)
{
    std::string key, value;
    while (file >> key >> value)
        insert(std::make_pair(key, value));
}

size_t HashTable2::hash(std::string key)
{
    size_t summ = 0;
    for (auto& symb : key)
        summ += symb;
    return summ % maxSize;
}

void HashTable2::insert(info_t pair)
{
    size_t position = hash(pair.first);
    while (table[position].used == 1 && table[position].info.first != pair.first) {
        position = (position + 1) % maxSize;
    }

    if (table[position].used != 1) {

        if (table[position].used == -1) {
            size_t tmp = position;

            while (table[tmp].used != 0 && table[tmp].info.first != pair.first)
                tmp = (tmp + 1) % maxSize;

            if (table[tmp].used == 0) {
                table[position].info = pair;
                table[position].used = 1;
            }
        }

        table[position].info = pair;
        table[position].used = 1;
    }
}

bool HashTable2::erase(std::string key)
{
    bool result = false;
    size_t position = hash(key);

    while (!(table[position].used == 0 || table[position].info.first == key && table[position].used == -1))
        position = (position + 1) % maxSize;

    if (table[position].used == 1) {
        result = true;
        table[position].used = -1;
    }

    return result;
}

bool HashTable2::find(std::string key, info_t& pair)
{
    size_t position = hash(key);
    bool result = false;

    while (!(table[position].used == 0 || table[position].info.first == key && table[position].used == 1))
        position = (position + 1) % maxSize;

    if (table[position].used == 1) {
        result = true;
        pair = table[position].info;
    }

    return result;
}

void HashTable2::view()
{
    size_t position;

    for (int i = 0; i < table.size(); ++i) {
        if (table[i].used == 1) {
            position = hash(table[i].info.first);
            std::cout << position << ". " << table[i].info.first << " - " << table[i].info.second << '\n';
        }
    }
    std::cout << '\n';
}
