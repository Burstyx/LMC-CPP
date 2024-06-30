#include "core/Instance.h"

#include <sstream>
#include <handlers/FsHandler.h>

#include "toml++/toml.hpp"

Instance::Instance(std::string name, std::string version, std::string loader)
    : _name(std::move(name)),
      _playing(false),
      _timePlayed(0),
      _lastPlayed(0),
      _version(std::move(version)),
      _loader(std::move(loader)) {
}

void Instance::saveToFile() {
    toml::table instance_table;
    instance_table.insert_or_assign("name", _name);
    instance_table.insert_or_assign("timePlayed", _timePlayed);
    instance_table.insert_or_assign("lastPlayed", _lastPlayed);

    toml::table minecraft_table;
    minecraft_table.insert_or_assign("instance", _version);
    minecraft_table.insert_or_assign("loader", _loader);

    toml::table root_table;
    root_table.insert_or_assign("instance", instance_table);
    root_table.insert_or_assign("minecraft", minecraft_table);

    std::stringstream ss;
    ss << root_table;

    createFile("instances\\" + _name, "instance.toml", ss.str());
}
