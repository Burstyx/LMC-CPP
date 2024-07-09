#pragma once
#include "Exceptions/Instances/InstanceException.h"

namespace LMC {
    class InstanceNotFoundException final : public InstanceException
    {
    public:
        explicit InstanceNotFoundException(const char* msg);
    };
}
