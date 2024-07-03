#include "commands/LaunchCommand.h"

#include <iostream>

const std::vector<std::string> & LaunchCommand::getAliases() const { return this->m_aliases; }
const std::vector<std::string> & LaunchCommand::getAuthorizedOptions() const { return this->m_authorizedOptions; }
const std::string & LaunchCommand::getHelp() const { return this->m_help; }

void LaunchCommand::handler(char *args[]) {
}

void LaunchCommand::launch() {
    std::cout << "start mc" << '\n';
}

void LaunchCommand::launch(const std::string& instanceName) {
    std::cout << "start mc " << instanceName << '\n';
}
