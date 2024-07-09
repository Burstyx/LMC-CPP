#pragma once
#include <exceptions/commands/CommandException.h>

class CommandInvalidArgumentsException final : public CommandException
{
public:
    explicit CommandInvalidArgumentsException(const char* msg);
};
