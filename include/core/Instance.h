#pragma once
#include <string>

class Instance final
{
    std::string _name;
    bool _playing;
    unsigned long _timePlayed;
    unsigned long _lastPlayed;

    std::string _version;
    std::string _loader;

public:
    explicit Instance(std::string name, std::string version, std::string loader);

    void saveToFile();
};
