#pragma once
#include <bits/shared_ptr.h>
#include <Instances/Instance.h>

#include "Minecraft/Minecraft.h"

namespace LMC {
    class Vanilla final : public Minecraft {
    public:
        explicit Vanilla(const Instance& instance);

        void IntegrityCheck();
    };
}
