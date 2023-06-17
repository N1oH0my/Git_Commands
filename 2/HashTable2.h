#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <Windows.h>

using info_t = std::pair<std::string, std::string>;

struct Cell
{
    info_t info;
    int used;
    Cell(info_t info = std::make_pair("",""), int used = 0) : info(info), used(used) {}
};

class HashTable2
{
private:
    std::vector<Cell> table;
    size_t maxSize;
public:
    HashTable2(size_t maxSize = 0);
    void fill(std::ifstream& file);
    size_t hash(std::string key);
    void insert(info_t pair);
    bool erase(std::string key);
    bool find(std::string key, info_t& pair);
    void view();
};