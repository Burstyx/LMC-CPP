#pragma once
#include <exception>

class InstanceException : public std::exception
{
    const char* message_;
    
public:
    explicit InstanceException(const char* msg) : message_(msg) { }
    
    [[nodiscard]] char const* what() const override { return message_; }
};
