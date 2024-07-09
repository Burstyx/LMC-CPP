#include "Handlers/CommandHandler.h"

#include "Commands/InstanceCommand.h"
#include "Commands/LaunchCommand.h"
#include "Exceptions/Commands/CommandInvalidArgumentsException.h"
#include "Exceptions/Commands/CommandNotFoundException.h"

#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <memory>

namespace LMC {
    void CommandHandler(const char* command, char* args[]) {
        if (const std::map<std::string, std::function<std::unique_ptr<CommandBase>()>> commands = {
            {"instance", [] { return std::make_unique<InstanceCommand>(); } },
            {"launch", [] { return std::make_unique<LaunchCommand>(); } }
        }; commands.find(command) != commands.end()) {
            const std::unique_ptr<CommandBase> cmd = commands.at(command)();

            try {
                cmd->Handler(args);
            } catch (const CommandInvalidArgumentsException& e) {
                std::cerr << e.what() << '\n';
                std::cout << cmd->GetHelp() << '\n';
            }
        } else {
            throw CommandNotFoundException("Command not found.");
        }
    }

    std::string ParseArgs(char* args[], const char* shortOption, const char* longOption, const char* defaultValue) {
        for (int i = 0; args[i] != nullptr; ++i)
            if ((strcmp(args[i], shortOption) == 0 || strcmp(args[i], longOption) == 0) && args[i + 1] != nullptr) return args[i + 1];
        return defaultValue;
    }
}