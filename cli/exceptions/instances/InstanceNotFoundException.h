#pragma once
#include <exceptions/instances/InstanceException.h>

class InstanceNotFoundException final : public InstanceException
{
public:
    explicit InstanceNotFoundException(const char* msg);
};
