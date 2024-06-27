#pragma once
#include "command_exception.h"

class command_not_found_exception final : public command_exception
{
public:
    explicit command_not_found_exception(const char* msg) : command_exception(msg) {}
};
