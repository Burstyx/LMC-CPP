#pragma once
#include "CommandException.h"

class CommandInvalidArgumentsException final : public CommandException
{
public:
    explicit CommandInvalidArgumentsException(const char* msg) : CommandException(msg) { }
};
