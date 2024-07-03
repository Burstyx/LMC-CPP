#pragma once
#include <map>
#include <string>
#include <vector>

class Command {
public:
    virtual ~Command() = default;

    [[nodiscard]] virtual const std::vector<std::string> &getAliases() const = 0;
    [[nodiscard]] virtual const std::vector<std::string> &getAuthorizedOptions() const = 0;
    [[nodiscard]] virtual const std::string &getHelp() const = 0;

    virtual void handler(char *args[]) = 0;
};
