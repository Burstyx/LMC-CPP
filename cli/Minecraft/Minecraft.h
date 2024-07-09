#pragma once
#include <string>

namespace LMC {
    class Minecraft {
    public:
        explicit Minecraft(std::string version);

    private:
        std::string m_Version;
    };
}
