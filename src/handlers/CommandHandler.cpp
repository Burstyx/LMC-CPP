#include "handlers/CommandHandler.h"

#include <cstring>
#include <iostream>
#include <commands/InstanceCommand.h>
#include <exceptions/commands/CommandInvalidArgumentsException.h>

#include "commands/LaunchCommand.h"
#include "exceptions/commands/CommandNotFoundException.h"

class CommandInvalidArgumentsException;
std::vector<Command*> commands = {
    new LaunchCommand(),
    new InstanceCommand()
};

void commandHandler(const char* command, char* args[]) {
    for (const auto& currentCmd : commands) {
        try {
            if (strcmp(command, currentCmd->name().c_str()) == 0) {
                currentCmd->handler(args);
                return;
            }

            for (const auto& alias : currentCmd->aliases()) {
                if (strcmp(command, alias.c_str()) == 0) {
                    currentCmd->handler(args);
                    return;
                }
            }
        } catch (const CommandInvalidArgumentsException& e) {
            std::cerr << e.what() << '\n';
            currentCmd->help();
        }
    }
    throw CommandNotFoundException(command);
}
