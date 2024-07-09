#pragma once
#include <string>

namespace LMC {
    class Instance final
    {
    public:
        Instance(std::string name, std::string version, std::string loader);
        explicit Instance(const std::string& path);

        [[nodiscard]] const std::string& GetName() const { return _name; };
        [[nodiscard]] const unsigned long& GetTimePlayed() const { return _timePlayed;};
        [[nodiscard]] const unsigned long& GetLastPlayed() const { return _lastPlayed; }
        [[nodiscard]] const std::string& GetVersion() const { return _version; }
        [[nodiscard]] const std::string& GetLoader() const { return _loader; };

        void SaveToFile();

    private:
        std::string _name;
        unsigned long _timePlayed;
        unsigned long _lastPlayed;

        std::string _version;
        std::string _loader;
    };
}