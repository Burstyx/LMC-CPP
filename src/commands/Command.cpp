#include "commands/Command.h"

Command::Command(std::string name, std::vector<std::string> aliases) : _name(std::move(name)), _aliases(std::move(aliases)) {
}

std::string Command::name() const {
    return _name;
}

std::vector<std::string> Command::aliases() const {
    return _aliases;
}
