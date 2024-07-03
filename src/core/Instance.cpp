#include "core/Instance.h"

#include <sstream>
#include <handlers/FsHandler.h>

#include "toml++/toml.hpp"

Instance::Instance(std::string name, std::string version, std::string loader)
    : _name(std::move(name)),
      _timePlayed(0),
      _lastPlayed(0),
      _version(std::move(version)),
      _loader(std::move(loader)) {
}

Instance::Instance(const std::string& path) {
    toml::table rootTable = toml::parse_file(path + "\\instance.toml");

    const auto instanceTable = rootTable["instance"].as_table();
    _name = instanceTable->get("name")->value_or("unknown");
    _timePlayed = instanceTable->get("timePlayed")->value_or(0);
    _lastPlayed = instanceTable->get("lastPlayed")->value_or(0);

    const auto mcTable = rootTable["minecraft"].as_table();
    _version = mcTable->get("instance")->value_or("latest");
    _loader = mcTable->get("loader")->value_or("vanilla");
}

const std::string &Instance::getName() const { return _name; }
const unsigned long &Instance::getTimePlayed() const { return _timePlayed;}
const unsigned long &Instance::getLastPlayed() const { return _lastPlayed; }
const std::string &Instance::getVersion() const { return _version; }
const std::string &Instance::getLoader() const { return _loader; }

void Instance::saveToFile() {
    toml::table instanceTable;
    instanceTable.insert_or_assign("name", _name);
    instanceTable.insert_or_assign("timePlayed", _timePlayed);
    instanceTable.insert_or_assign("lastPlayed", _lastPlayed);

    toml::table mcTable;
    mcTable.insert_or_assign("instance", _version);
    mcTable.insert_or_assign("loader", _loader);

    toml::table rootTable;
    rootTable.insert_or_assign("instance", instanceTable);
    rootTable.insert_or_assign("minecraft", mcTable);

    std::stringstream ss;
    ss << rootTable;

    createFile("instances\\" + _name, "instance.toml", ss.str());
}
