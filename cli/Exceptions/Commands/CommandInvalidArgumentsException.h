#pragma once
#include "Exceptions/Commands/CommandException.h"

namespace LMC {
    class CommandInvalidArgumentsException final : public CommandException
    {
    public:
        explicit CommandInvalidArgumentsException(const char* msg);
    };
}
