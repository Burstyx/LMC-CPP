#include "Commands/InstanceCommand.h"

#include "Instances/Instance.h"
#include "Exceptions/Commands/CommandInvalidArgumentsException.h"
#include "Exceptions/Commands/CommandNotFoundException.h"
#include "Core/FileSystem.h"

#include <iostream>
#include <cstring>

#include "CommandHandler.h"

namespace LMC {
    void InstanceCommand::Handler(char* args[]) {
        if (args[0] == nullptr)
            throw CommandInvalidArgumentsException("No subcommand provided.");

        if (strcmp(args[0], "create") == 0) {
            const std::vector<std::pair<std::string, std::string>> expectedArgs = {
                {"-n", "--name"}, // REQUIRED
                {"-v", "--version"},
                {"-l", "--loader"},
            };

            const std::unordered_map<std::string, std::string> parsedArgs = CommandHandler::ParseArgs(args + 1, expectedArgs);

            const std::string name = CommandHandler::GetValue(expectedArgs[0], parsedArgs);
            if(name.empty())
                throw CommandInvalidArgumentsException("Name argument is invalid.");

            const std::string version = CommandHandler::GetValueOrDefault(expectedArgs[1], parsedArgs, "latest");
            const std::string loader = CommandHandler::GetValueOrDefault(expectedArgs[2], parsedArgs, "vanilla");

            Create(name, version, loader);
        } else if(strcmp(args[0], "remove") == 0) {
            const std::vector<std::pair<std::string, std::string>> expectedArgs = {
                {"-n", "--name"}, // REQUIRED
            };

            const std::unordered_map<std::string, std::string> parsedArgs = CommandHandler::ParseArgs(args + 1, expectedArgs);

            const std::string name = CommandHandler::GetValue(expectedArgs[0], parsedArgs);
            if(name.empty())
                throw CommandInvalidArgumentsException("Name argument is invalid.");

            Remove(name);
        }
        else if(strcmp(args[0], "list") == 0) {
            List();
        }
        else {
            throw CommandInvalidArgumentsException("Subcommand doesn't exist.");
        }
    }

    std::string InstanceCommand::GetHelp() {
        return "Manage Minecraft instances.\n"
                 "\n"
                 "Usage: lmc instance [options]\n"
                 "\n"
                 "Options:\n"
                 " * create --name <name> [--version <version=\"1.12.2\">] [--loader <loader=\"vanilla\">]: Create a new Minecraft instance.\n"
                 " * remove --name <name>: Remove a Minecraft instance.\n"
                 " * list: List all Minecraft instances.\n"
                 " * get --name <name>: List data about a specific Minecraft instance.";
    }


    void InstanceCommand::Create(const std::string& name, const std::string& version, const std::string& loader) {
        const Instance instance(name, version, loader);
        instance.SaveToFile();
    }

    void InstanceCommand::Remove(const std::string& name) {
        const Instance instance = Instance::GetInstanceFromName(name);
        instance.DeleteFile();
    }

    void InstanceCommand::List() {
        for (const auto &folder : FileSystem::GetFolders("instances")) {
            try {
                Instance instance(folder);
                std::cout << " * " << instance.GetName() << " | " << instance.GetVersion() << " | " << instance.GetLoader() << '\n';
            } catch(const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }

    }

    void InstanceCommand::Get(const std::string& name) {

    }
}
