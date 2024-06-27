#pragma once
#include "command_exception.h"

class command_invalid_arguments_exception final : public command_exception
{
public:
    explicit command_invalid_arguments_exception(const char* msg) : command_exception(msg) { }
};
