#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <fstream>

class HashTable_1
{
private:
    std::vector<std::list<std::pair<std::string, std::string>>> table;
    size_t maxSize;
public: 
    HashTable_1() {};
    HashTable_1(size_t maxSize);
    ~HashTable_1() {};
    void fill(std::ifstream& file);
    size_t hash(std::string key);
    void insert(std::pair<std::string, std::string> pair);
    bool erase(std::string key);
    bool find(std::string key, std::pair<std::string, std::string>& pair);
    void view();
};