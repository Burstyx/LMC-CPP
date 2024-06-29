#pragma once
#include "InstanceException.h"

class InstanceNotFoundException final : public InstanceException
{
public:
    explicit InstanceNotFoundException(const char* msg);
};
