#include "handlers/CommandHandler.h"

#include <cstring>
#include <iostream>
#include <exceptions/commands/CommandInvalidArgumentsException.h>

#include "commands/LaunchCommand.h"
#include "exceptions/commands/CommandNotFoundException.h"


void commandHandler(const char *command, char *args[], const std::vector<Command*> &commands) {
    for (const auto &currentCmd : commands) {
        try {
            for (const auto &alias : currentCmd->getAliases()) {
                if (strcmp(command, alias.c_str()) == 0) {
                    currentCmd->handler(args);
                    return;
                }
            }
        } catch (const CommandInvalidArgumentsException& e) {
            std::cerr << e.what() << '\n';
            std::cout << currentCmd->getHelp() << '\n';
        }
    }
    throw CommandNotFoundException(command);
}

std::string parseArgs(char *args[], const char *shortOption, const char *longOption, const char *defaultValue) {
    for (int i = 0; args[i] != nullptr; ++i)
        if ((strcmp(args[i], shortOption) == 0 || strcmp(args[i], longOption) == 0) && args[i + 1] != nullptr) return args[i + 1];
    return defaultValue;
}