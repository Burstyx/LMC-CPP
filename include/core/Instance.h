#pragma once
#include <string>

class Instance final
{
    std::string _name;
    unsigned long _timePlayed;
    unsigned long _lastPlayed;

    std::string _version;
    std::string _loader;

public:
    Instance(std::string name, std::string version, std::string loader);
    Instance(const std::string& path);

    [[nodiscard]] const std::string &getName() const;
    [[nodiscard]] const unsigned long &getTimePlayed() const;
    [[nodiscard]] const unsigned long &getLastPlayed() const;
    [[nodiscard]] const std::string &getVersion() const;
    [[nodiscard]] const std::string &getLoader() const;

    void saveToFile();
};
