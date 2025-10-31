#pragma once

#include "mapping.hpp"

class matchBuilder {
public:
    // Function to generate a random match using the native C++ structs
    static mapping::Match randomMatch();
};
