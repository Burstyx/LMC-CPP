#pragma once
#include <string>
#include <vector>

class command
{
public:
    const char* name;
    std::vector<std::string> alias;

    command();
};
