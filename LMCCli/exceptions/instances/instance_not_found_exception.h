#pragma once
#include "instance_exception.h"

class InstanceNotFoundException final : public InstanceException
{
public:
    explicit InstanceNotFoundException(const char* msg) : InstanceException(msg) { }
};
