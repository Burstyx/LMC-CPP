#include "Commands/InstanceCommand.h"

#include "Core/Instance.h"
#include "Exceptions/Commands/CommandInvalidArgumentsException.h"
#include "Exceptions/Commands/CommandNotFoundException.h"
#include "Commands/CommandHandler.h"
#include "Core/FileSystem.h"

#include <iostream>
#include <cstring>

namespace LMC {
    void InstanceCommand::Handler(char* args[]) {
        if (args[0] == nullptr) throw CommandInvalidArgumentsException("No subcommand provided.");

        if (strcmp(args[0], "create") == 0) {
            if(args[1] == nullptr) throw CommandInvalidArgumentsException("No instance name provided.");

            const std::string version = ParseArgs(args + 2, "-v", "--version", "latest");
            const std::string loader = ParseArgs(args + 2, "-l", "--loader", "vanilla");

            Create(args[1], version, loader);
        } else if(strcmp(args[0], "list") == 0) {
            List();
        }
        else {
            throw CommandNotFoundException("Subcommand doesn't exist.");
        }
    }

    std::string InstanceCommand::GetHelp() {
        return "Manage Minecraft instances.\n"
                 "\n"
                 "Usage: lmc instance [options]\n"
                 "\n"
                 "Options:\n"
                 " * create <name> [-v | --version=\"1.12.2\"] [-l | --loader=\"vanilla\"]: Create a new Minecraft instance.\n"
                 " * remove <name>: Remove a Minecraft instance.\n"
                 " * list: List all Minecraft instances.\n"
                 " * get <name>: List data about a specific Minecraft instance.";
    }


    void InstanceCommand::Create(const std::string& name, const std::string& version, const std::string& loader) {
        Instance instance(name, version, loader);
        instance.SaveToFile();
    }

    void InstanceCommand::Remove(const std::string& name) {
    }

    void InstanceCommand::List() {
        for (const auto &folder : GetFolders("instances")) {
            try {
                Instance instance(folder);
                std::cout << "> " << instance.GetName() << " " << instance.GetVersion() << " " << instance.GetLoader() << '\n';
            } catch(const std::exception &e) {
                std::cerr << e.what() << std::endl;
            }
        }

    }

    void InstanceCommand::Get(const std::string& name) {

    }
}