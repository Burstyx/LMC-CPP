#pragma once
#include <string>
#include <vector>

class command
{
protected:
    ~command() = default;

public:
    const std::string name;
    std::vector<std::string> aliases;

    command(std::string name, const std::vector<std::string>& aliases) : name(std::move(name)), aliases(aliases) {}

    /**
    * Handle arguments
    *
    * @param args Command arguments
    * @throw command_invalid_arguments_exception If arguments are invalid
     */
    virtual void handler(const char* args[]) = 0;

    /**
     * Print help message
     */
    virtual void help() = 0;
};
