#pragma once
#include <string>
#include <bits/shared_ptr.h>
#include <Instances/Instance.h>

namespace LMC {
    class Minecraft {
    public:
        explicit Minecraft(Instance instance);

    private:
        Instance m_Instance;
    };
}
