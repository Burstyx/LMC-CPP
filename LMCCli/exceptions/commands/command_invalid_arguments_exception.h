#pragma once
#include "command_exception.h"

class CommandInvalidArgumentsException final : public CommandException
{
public:
    explicit CommandInvalidArgumentsException(const char* msg) : CommandException(msg) { }
};
