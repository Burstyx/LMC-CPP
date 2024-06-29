#include "handlers/CommandHandler.h"

#include <cstring>

#include "commands/LaunchCommand.h"
#include "exceptions/commands/CommandNotFoundException.h"

std::vector<Command*> commands = {
    new LaunchCommand()
};

void commandHandler(const char* command, char* args[]) {
    for (const auto& currentCmd : commands) {
        if (strcmp(command, currentCmd->name().c_str()) == 0) {
            currentCmd->handler(args);
            return;
        }
    }
    throw CommandNotFoundException(command);
}
