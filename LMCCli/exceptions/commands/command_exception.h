#pragma once
#include <exception>

class command_exception : public std::exception
{
    const char* message_;
    
public:
    explicit command_exception(const char* msg);
    char const* what() const override;
};
