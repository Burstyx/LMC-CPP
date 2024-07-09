#include "Commands/CommandHandler.h"

#include "InstanceCommand.h"
#include "LaunchCommand.h"
#include "Exceptions/Commands/CommandInvalidArgumentsException.h"
#include "Exceptions/Commands/CommandNotFoundException.h"

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

    std::unordered_map<std::string, std::optional<std::string>> ParseArgs(char* args[], const std::vector<std::pair<std::string, std::string>>& expectedArgs) {
        std::unordered_map<std::string, std::optional<std::string>> parsedArgs;
        // Loop all arguments in args
        for (size_t i = 0; args[i] != nullptr; i++) {
            // Loop all expected arguments
            for (const auto& [shortArg, longArg] : expectedArgs) {
                // Check if the argument is the expected argument
                if (args[i] == shortArg || args[i] == longArg) {
                    // Check if the next argument is not null
                    if (args[i + 1] != nullptr) {
                        // Add the argument to the map
                        parsedArgs[shortArg] = args[i + 1];
                    }
                }
            }
        }
    }
}
