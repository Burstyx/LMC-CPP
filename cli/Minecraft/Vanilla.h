#pragma once
#include "Minecraft/Minecraft.h"

namespace LMC {
    class Vanilla final : public Minecraft {
    public:
        explicit Vanilla(std::string version);
    };
}
