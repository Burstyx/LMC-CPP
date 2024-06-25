#pragma once
#include <map>
#include <string>
#include <vector>

class Command
{
public:
    
    
    virtual void execute(std::map<std::string, std::string> options) = 0;
    virtual void help() = 0;
    
    virtual ~Command() = default;
};
