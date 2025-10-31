#include "myRandom.hpp"

#include <iostream>
#include <random>
#include <string>

#include "dependencies/json.hpp"

// Constructor to initialize the random number generator with a seed.
// These are declared static so there is only one instance across all objects
// of the myRandom class.
thread_local std::random_device myRandom::rd;
thread_local std::mt19937 myRandom::gen(myRandom::rd());

int myRandom::generateRandomInt(int min, int max)
{
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
};

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

// Helper: get N unique random keys from a map (without replacement when possible);
static std::vector<int> getRandomKeysCached(const std::unordered_map<int, std::string> &m, size_t count)
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

// Helper: cache keys of a map for efficient repeated sampling;
static int getRandomKeyCached(const std::unordered_map<int, std::string> &m)
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

std::vector<int> myRandom::distributeTotal(int total, int count)
{
    std::vector<int> result(count, 0);
    for (int i = 0; i < total; ++i)
    {
        result[generateRandomInt(0, count - 1)]++;
    }
    return result;
}
