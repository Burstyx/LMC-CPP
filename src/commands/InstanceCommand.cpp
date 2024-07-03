#include "commands/InstanceCommand.h"

#include <iostream>
#include <cstring>
#include <utility>
#include <core/Instance.h>
#include <exceptions/commands/CommandInvalidArgumentsException.h>
#include <exceptions/commands/CommandNotFoundException.h>
#include <handlers/CommandHandler.h>
#include <handlers/FsHandler.h>

InstanceCommand::InstanceCommand(std::vector<std::string> aliases, std::vector<std::string> authorizedOptions) {
    this->m_aliases = std::move(aliases);
    this->m_authorizedOptions = std::move(authorizedOptions);
}

const std::vector<std::string> &InstanceCommand::getAliases() const { return this->m_aliases; }
const std::vector<std::string> &InstanceCommand::getAuthorizedOptions() const { return this->m_authorizedOptions; }
const std::string &InstanceCommand::getHelp() const { return this->m_help; }

void InstanceCommand::handler(char *args[]) {
    if (args[0] == nullptr) throw CommandInvalidArgumentsException("No subcommand provided.");

    if (strcmp(args[0], "create") == 0) {
        if(args[1] == nullptr) throw CommandInvalidArgumentsException("No instance name provided.");

        const std::string version = parseArgs(args + 2, "-v", "--version", "latest");
        const std::string loader = parseArgs(args + 2, "-l", "--loader", "vanilla");

        this->create(args[1], version, loader);
    } else if(strcmp(args[0], "list") == 0) {
        this->list();
    }
    else {
        throw CommandNotFoundException("Subcommand doesn't exist.");
    }
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
