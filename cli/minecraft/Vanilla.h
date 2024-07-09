#pragma once
#include <minecraft/Minecraft.h>

class Vanilla final : public Minecraft {
public:
    explicit Vanilla(std::string version);
};
