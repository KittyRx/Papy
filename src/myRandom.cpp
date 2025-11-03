#include "myRandom.hpp"

#include <iostream>
#include <random>
#include <string>
#include <unordered_set>

#include "dependencies/json.hpp"

thread_local std::random_device myRandom::rd;
thread_local std::mt19937 myRandom::gen(myRandom::rd());

int myRandom::generateRandomInt(int min, int max)
{
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
};

std::pair<std::vector<int>, std::vector<int>> myRandom::generateUniqueIntsPair(
    int min1, int max1, int count1,
    int min2, int max2, int count2
) {
    std::vector<int> result1;
    std::unordered_set<int> used1;
    
    while (result1.size() < count1) {
        int value = myRandom::generateRandomInt(min1, max1);
        if (used1.find(value) == used1.end()) {
            result1.push_back(value);
            used1.insert(value);
        }
    }
    
    std::vector<int> result2;
    std::unordered_set<int> used2;
    
    while (result2.size() < count2) {
        int value = myRandom::generateRandomInt(min2, max2);
        if (used2.find(value) == used2.end()) {
            result2.push_back(value);
            used2.insert(value);
        }
    }
    
    return {result1, result2};
}

std::string myRandom::generateRandomString(size_t length)
{
    constexpr char chars[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    constexpr size_t chars_len = sizeof(chars) - 1;

    static std::uniform_int_distribution<> distrib(0, chars_len - 1);

    std::string randomStr;
    randomStr.reserve(length);
    for (size_t i = 0; i < length; ++i)
    {
        randomStr += chars[distrib(gen)];
    }
    return randomStr;
};

std::string myRandom::generateRandomNumberString(size_t length)
{
    constexpr char chars[] = "0123456789";
    constexpr size_t chars_len = sizeof(chars) - 1;

    static std::uniform_int_distribution<> distrib(0, chars_len - 1);

    std::string randomStr;
    randomStr.reserve(length);
    for (size_t i = 0; i < length; ++i)
    {
        randomStr += chars[distrib(gen)];
    }
    return randomStr;
};

bool myRandom::getRandomBool()
{
    static std::uniform_int_distribution<> distrib(0, 1);

    // Return true if random number is 1, else false
    return distrib(gen) == 1;
};

/**
 * @brief Takes an unordered map and caches the key list for all members then returns a `count` ammount of random `IDs` inside a vector;
 * 
 * @param a A reference to the `Unordered_map<int, string>` that needs sampling;
 * @param b The number of keys you want to retrieve from the map;
 * @return Returns a `vector<int>` with the `IDs` of `count` random elements from inside the map;
**/
std::vector<int> myRandom::getRandomKeysCached(const std::unordered_map<int, std::string> &m, size_t count)
{
    static std::unordered_map<const std::unordered_map<int, std::string> *, std::vector<int>> keyCache;
    auto it = keyCache.find(&m);
    if (it == keyCache.end())
    {
        std::vector<int> keys;
        keys.reserve(m.size());
        for (const auto &p : m)
            keys.push_back(p.first);
        auto res = keyCache.emplace(&m, std::move(keys));
        it = res.first;
    }
    const auto &keys = it->second;
    std::vector<int> out;
    if (keys.empty())
        return out;

    if (count >= keys.size())
    {
        // Not enough unique keys: sample with replacement;
        out.reserve(count);
        for (size_t i = 0; i < count; ++i)
        {
            int idx = myRandom::generateRandomInt(0, (int)keys.size() - 1);
            out.push_back(keys[idx]);
        }
        return out;
    }

    std::vector<int> tmp = keys;
    for (size_t i = 0; i < count; ++i)
    {
        int j = myRandom::generateRandomInt((int)i, (int)tmp.size() - 1);
        std::swap(tmp[i], tmp[j]);
        out.push_back(tmp[i]);
    }
    return out;
};

/**
 * @brief Takes an unordered map and caches the key list for each member;
 * 
 * @param a A reference to the `Unordered_map<int, string>` that needs sampling;
 * @return Returns an `int` with the `ID` of a random element;
**/
int myRandom::getRandomKeyCached(const std::unordered_map<int, std::string> &m)
{
    static std::unordered_map<const std::unordered_map<int, std::string> *, std::vector<int>> keyCache;
    auto it = keyCache.find(&m);
    if (it == keyCache.end())
    {
        std::vector<int> keys;
        keys.reserve(m.size());
        for (const auto &p : m)
            keys.push_back(p.first);
        auto res = keyCache.emplace(&m, std::move(keys));
        it = res.first;
    }
    const auto &keys = it->second;
    if (keys.empty())
        return 0;
    int idx = myRandom::generateRandomInt(0, (int)keys.size() - 1);
    return keys[idx];
};

/**
 * @brief Takes a total value of `int` then distributes that across members pseudo randomly;
 * 
 * @param a Integer value representing the total value to be distributed;
 * @return Returns a `array<int, 5>` with values randomly distributed for each member that are = total value;
**/
std::array<int, 5> myRandom::distributeTotal(int total)
{
    std::array<int, 5> result = {}; // Zero-initialize all 5 elements
    for (int i = 0; i < total; ++i)
    {
        result[generateRandomInt(0, 4)]++; // 0 to 4 for 5 elements
    }
    return result;
}
