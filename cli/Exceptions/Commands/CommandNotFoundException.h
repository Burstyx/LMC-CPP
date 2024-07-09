#pragma once
#include "Exceptions/Commands/CommandException.h"

namespace LMC {
    class CommandNotFoundException final : public CommandException
    {
    public:
        explicit CommandNotFoundException(const char* msg);
    };
}
