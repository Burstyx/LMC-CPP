#pragma once
#include <string>
#include <bits/shared_ptr.h>
#include <Instances/Instance.h>

namespace LMC {
    class Minecraft {
    public:
        explicit Minecraft(const std::shared_ptr<Instance>& instance);

    private:
        std::shared_ptr<Instance> m_Instance;
    };
}
