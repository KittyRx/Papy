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
    static std::array<int, 5> distributeTotal(int total);
    static std::pair<std::vector<int>, std::vector<int>> myRandom::generateUniqueIntsPair(
        int min1, int max1, int count1,
        int min2, int max2, int count2);

private:
    static thread_local std::random_device rd; // Seed source
    static thread_local std::mt19937 gen;
};
