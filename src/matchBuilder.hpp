#pragma once

#include "mapping.hpp"
#include "dependencies/json.hpp"

class matchBuilder {
public:
    // Function to generate a random match and return it as JSON
    static nlohmann::json randomMatch();
};
