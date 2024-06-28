#pragma once
#include <exception>

class CommandException : public std::exception
{
    const char* message_;
    
public:
    explicit CommandException(const char* msg) : message_(msg) { }
    
    char const* what() const override { return message_; }
};
