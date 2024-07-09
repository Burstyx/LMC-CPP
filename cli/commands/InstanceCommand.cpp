#include "commands/InstanceCommand.h"

#include <iostream>
#include <cstring>
#include <core/Instance.h>
#include <exceptions/commands/CommandInvalidArgumentsException.h>
#include <exceptions/commands/CommandNotFoundException.h>
#include <handlers/CommandHandler.h>
#include <handlers/FsHandler.h>

void InstanceCommand::handler(char *args[]) {
    if (args[0] == nullptr) throw CommandInvalidArgumentsException("No subcommand provided.");

    if (strcmp(args[0], "create") == 0) {
        if(args[1] == nullptr) throw CommandInvalidArgumentsException("No instance name provided.");

        const std::string version = parseArgs(args + 2, "-v", "--version", "latest");
        const std::string loader = parseArgs(args + 2, "-l", "--loader", "vanilla");

        create(args[1], version, loader);
    } else if(strcmp(args[0], "list") == 0) {
        list();
    }
    else {
        throw CommandNotFoundException("Subcommand doesn't exist.");
    }
}

std::string InstanceCommand::getHelp() {
    return "Manage Minecraft instances.\n"
             "\n"
             "Usage: lmc instance [options]\n"
             "\n"
             "Options:\n"
             "  create <name> [-v | --version=\"1.12.2\"] [-l | --loader=\"vanilla\"]  Create a new Minecraft instance.\n"
             "  remove <name>                                                          Remove a Minecraft instance.\n"
             "  list                                                                   List all Minecraft instances.\n"
             "  get <name>                                                             List data about a specific Minecraft instance.";
}


void InstanceCommand::create(const std::string &name, const std::string &version, const std::string &loader) {
    Instance instance(name, version, loader);
    instance.saveToFile();
}

void InstanceCommand::remove(const std::string &name) {
}

void InstanceCommand::list() {
    for (const auto &folder : getFolders("instances")) {
        try {
            Instance instance(folder);
            std::cout << "> " << instance.getName() << " " << instance.getVersion() << " " << instance.getLoader() << '\n';
        } catch(const std::exception &e) {  }
    }

}

void InstanceCommand::get(const std::string &name) {

}