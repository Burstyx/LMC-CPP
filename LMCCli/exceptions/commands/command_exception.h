#pragma once
#include <exception>

class command_exception : public std::exception
{
    const char* message_;
    
public:
    explicit command_exception(const char* msg) : message_(msg) { }
    
    char const* what() const override { return message_; }
};
