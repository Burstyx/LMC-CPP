#include "core/Instance.h"

#include <toml++/impl/std_optional.hpp>

Instance::Instance(std::string name, std::string version) : _name(std::move(name)), _version(std::move(version)), _playing(false) {
}
