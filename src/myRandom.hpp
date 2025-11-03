#pragma once

#include <random>
#include <string>

#include "dependencies/json.hpp"

class myRandom
{
public:
    static int generateRandomInt(int min, int max);
    static std::string generateRandomString(size_t length);
    static std::string generateRandomNumberString(size_t length);
    static bool getRandomBool();
    static int getRandomKeyCached(const std::unordered_map<int, std::string> &m);
    static std::vector<int> getRandomKeysCached(const std::unordered_map<int, std::string> &m, size_t count);
    static std::vector<int> distributeTotal(int total, int count);
    static std::vector<int> generateUniqueInts(int min, int max, int count);
    
private:
    static thread_local std::random_device rd; // Seed source
    static thread_local std::mt19937 gen;
};
