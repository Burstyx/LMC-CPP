#pragma once
#include <string>

namespace LMC {
    class Instance final {
    public:
        Instance(std::string name, std::string version, std::string loader);
        explicit Instance(const std::string& path);

        void SaveToFile() const;
        void DeleteFile() const;
        [[nodiscard]] const std::string& GetName() const { return m_Name; }
        [[nodiscard]] unsigned long GetTimePlayed() const { return m_TimePlayed; }
        [[nodiscard]] unsigned long GetLastPlayed() const { return m_LastPlayed; }
        [[nodiscard]] const std::string& GetVersion() const { return m_Version; }
        [[nodiscard]] const std::string& GetLoader() const { return m_Loader; }

        [[nodiscard]] static Instance GetInstanceFromName(const std::string &name);

    private:
        std::string m_Name;
        unsigned long m_TimePlayed = 0;
        unsigned long m_LastPlayed = 0;
        std::string m_Version;
        std::string m_Loader;
    };
}