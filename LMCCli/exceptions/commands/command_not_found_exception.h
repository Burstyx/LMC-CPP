#pragma once
#include "command_exception.h"

class CommandNotFoundException final : public CommandException
{
public:
    explicit CommandNotFoundException(const char* msg) : CommandException(msg) {}
};
