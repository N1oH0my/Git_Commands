#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using info_t = std::pair<std::string, std::string>;

struct Cell
{
    info_t info;
    bool used;
    Cell(info_t info = std::make_pair("", ""), bool used = false) : info(info), used(used) {}
};

class HashTable3
{
private:
    std::vector<Cell> table;
    size_t maxSize, size;
public:
    HashTable3(size_t maxSize = 0);
    ~HashTable3() {};

    size_t hash(std::string key);

    bool insert(info_t pair);
    bool erase(std::string key);

    bool find(std::string key, info_t& pair);

    void fill(std::ifstream& file);
    void view();
};