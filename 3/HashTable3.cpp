#include "HashTable3.h"

HashTable3::HashTable3(size_t maxSize)
{
    this->maxSize = maxSize;
    table.resize(maxSize);
}

size_t HashTable3::hash(std::string key)
{
    size_t summ = 0;

    for (auto& symb : key)
        summ += symb;

    return summ % maxSize;
}

bool HashTable3::insert(info_t pair)
{
    bool result = false;
    size_t position = hash(pair.first);

    while (table[position].info.first != pair.first && table[position].used)
        position = (position + 1) % maxSize;

    if (!table[position].used) {
        result = true;
        table[position].info = pair;
        table[position].used = true;
    }

    return result;
}

bool HashTable3::erase(std::string key)
{
    auto dist = [this](size_t i, size_t j) {
        return (maxSize + j - i) % maxSize;
    };

    bool result = false;
    size_t window = hash(key);

    while (table[window].used && table[window].info.first != key)
        window = (window + 1) % maxSize;

    if (table[window].used) {

    }

    return result;
}

bool HashTable3::find(std::string key, info_t& pair)
{
    size_t position = hash(key);
    bool result = false;

    while (!(table[position].used == 0 || table[position].info.first == key && table[position].used == 1))
        position = (position + 1) % maxSize;

    if (table[position].used) {
        result = true;
        pair = table[position].info;
    }

    return result;
}

void HashTable3::fill(std::ifstream& file)
{
    std::string key, value;

    while (file >> key >> value)
        insert(std::make_pair(key, value));
}

void HashTable3::view()
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
