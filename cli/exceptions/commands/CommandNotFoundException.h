#pragma once
#include <exceptions/commands/CommandException.h>

class CommandNotFoundException final : public CommandException
{
public:
    explicit CommandNotFoundException(const char* msg);
};
