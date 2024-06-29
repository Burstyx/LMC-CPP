#include "core/Instance.h"

Instance::Instance(std::string name, std::string version) : _name(std::move(name)), _version(std::move(version)), _playing(false) {
}
