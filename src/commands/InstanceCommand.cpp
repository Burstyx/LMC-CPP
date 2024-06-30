#include "commands/InstanceCommand.h"

#include <iostream>
#include <core/Instance.h>

void InstanceCommand::create(const std::string &name, const std::string &version, const std::string &loader) {
    Instance instance(name, version, loader);
    instance.saveToFile();
}

void InstanceCommand::handler(char *args[]) {
    std::cout << "Creating instance..." << '\n';

    this->create("test", "1.12.2", "vanilla");

    std::cout << "Instance created!" << '\n';
}

void InstanceCommand::help() {
}
