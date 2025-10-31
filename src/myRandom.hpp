#pragma once

#include <random>
#include <string>

#include "dependencies/json.hpp"

class myRandom
{
public:
    // Generates a random integer between min and max (inclusive)
    static int generateRandomInt(int min, int max);

    // Generates a random string of a specified length containing letters and digits
    static std::string generateRandomString(size_t length);

    // Generates a random numeric string of a specified length
    static std::string generateRandomNumberString(size_t length);

    // Generates a random boolean (true or false)
    static bool getRandomBool();

    // Used to itterate through structs and return a random key.
    static int getRandomKeyCached(const std::unordered_map<int, std::string> &m);

    // Same but returns several values in the form of a vector.
    static std::vector<int> getRandomKeysCached(const std::unordered_map<int, std::string> &m, size_t count);

    // Random stats distribution
    static std::vector<int> distributeTotal(int total, int count);

private:
    static thread_local std::random_device rd; // Seed source
    static thread_local std::mt19937 gen;
};
