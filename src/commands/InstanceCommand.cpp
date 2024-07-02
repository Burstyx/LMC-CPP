#include "commands/InstanceCommand.h"

#include <iostream>
#include <cstring>
#include <core/Instance.h>
#include <exceptions/commands/CommandInvalidArgumentsException.h>

void InstanceCommand::create() {
    Instance instance(_name, , loader);
    instance.saveToFile();
}

void InstanceCommand::handler(char *args[]) {
    if (args[0] == nullptr) throw CommandInvalidArgumentsException("No command has been provided.");

}

void InstanceCommand::help() {
}
