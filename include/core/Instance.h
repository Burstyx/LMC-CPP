#pragma once
#include <string>

class Instance final
{
    std::string _name;
    std::string _version;
    bool _playing;
    
public:
    explicit Instance(std::string name, std::string version);
};
