#include "commands/InstanceCommand.h"

#include <core/Instance.h>

void InstanceCommand::create(const std::string &name, const std::string &version, const std::string &loader) {
    Instance instance(name, version, loader);
    instance.saveToFile();
}
