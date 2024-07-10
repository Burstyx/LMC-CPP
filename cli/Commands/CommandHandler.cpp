#include "Commands/CommandHandler.h"

#include "InstanceCommand.h"
#include "LaunchCommand.h"
#include "Exceptions/Commands/CommandInvalidArgumentsException.h"
#include "Exceptions/Commands/CommandNotFoundException.h"

#include <functional>
#include <iostream>
#include <map>
#include <memory>

namespace LMC::CommandHandler {
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

    bool IsValidArg(const char* arg, const std::vector<std::pair<std::string, std::string>>& expectedArgs) {
        return std::any_of(expectedArgs.begin(), expectedArgs.end(), [&arg](const auto& pair) {
            return arg == pair.first || arg == pair.second;
        });
    }

    std::unordered_map<std::string, std::string> ParseArgs(char* args[], const std::vector<std::pair<std::string, std::string>>& expectedArgs) {
        std::unordered_map<std::string, std::string> parsedArgs;

        for (size_t i = 0; args[i] != nullptr; i++) {
            if(IsValidArg(args[i], expectedArgs)) {
                if (args[i + 1] != nullptr) {
                    if(!IsValidArg(args[i + 1], expectedArgs)) {
                        parsedArgs[args[i]] = args[i + 1];
                        i++;

                        continue;
                    }
                }

                parsedArgs[args[i]] = "";
                i++;
            } else throw CommandInvalidArgumentsException("Invalid argument.");
        }
        return parsedArgs;
    }

    std::string GetValue(const std::pair<std::string, std::string>& expectedKeys, const std::unordered_map<std::string, std::string>& parsedArgs) {
        return parsedArgs.find(expectedKeys.first) != parsedArgs.end() ? parsedArgs.at(expectedKeys.first) : parsedArgs.find(expectedKeys.second) != parsedArgs.end() ? parsedArgs.at(expectedKeys.second) : throw CommandInvalidArgumentsException("A required argument wasn't specified.");
    }

    std::string GetValueOrDefault(const std::pair<std::string, std::string>& expectedKeys, const std::unordered_map<std::string, std::string>& parsedArgs, const std::string& defaultValue) {
        return parsedArgs.find(expectedKeys.first) != parsedArgs.end() ? parsedArgs.at(expectedKeys.first) : parsedArgs.find(expectedKeys.second) != parsedArgs.end() ? parsedArgs.at(expectedKeys.second) : defaultValue;
    }
}
