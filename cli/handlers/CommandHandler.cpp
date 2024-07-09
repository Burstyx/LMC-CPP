#include "CommandHandler.h"

#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>
#include <commands/InstanceCommand.h>
#include "commands/LaunchCommand.h"
#include "exceptions/commands/CommandNotFoundException.h"


void commandHandler(const char* command, char* args[]) {
    if (const std::map<std::string, std::function<std::unique_ptr<Command>()>> commands = {
        {"instance", [] { return std::make_unique<InstanceCommand>(); } },
        {"launch", [] { return std::make_unique<LaunchCommand>(); } }
    }; commands.find(command) != commands.end()) {
        commands.at(command)()->handler(args);
    } else {
        throw CommandNotFoundException("Command not found.");
    }
}

std::string parseArgs(char *args[], const char *shortOption, const char *longOption, const char *defaultValue) {
    for (int i = 0; args[i] != nullptr; ++i)
        if ((strcmp(args[i], shortOption) == 0 || strcmp(args[i], longOption) == 0) && args[i + 1] != nullptr) return args[i + 1];
    return defaultValue;
}