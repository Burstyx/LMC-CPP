#include "handlers/CommandHandler.h"

#include <cstring>
#include <commands/InstanceCommand.h>

#include "commands/LaunchCommand.h"
#include "exceptions/commands/CommandNotFoundException.h"

std::vector<Command*> commands = {
    new LaunchCommand(),
    new InstanceCommand()
};

void commandHandler(const char* command, char* args[]) {
    for (const auto& currentCmd : commands) {
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
    }
    throw CommandNotFoundException(command);
}
