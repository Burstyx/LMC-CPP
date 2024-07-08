#pragma once
#include <exception>

class CommandException : public std::exception
{
    const char* message_;
    
public:
    explicit CommandException(const char* msg);

    [[nodiscard]] const char* what() const noexcept override;
};
