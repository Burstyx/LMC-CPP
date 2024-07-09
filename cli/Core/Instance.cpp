#include "Core/Instance.h"

#include "Handlers/FsHandler.h"

#include <sstream>
#include <toml++/toml.hpp>

namespace LMC {
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

    void Instance::SaveToFile() {
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

        CreateFile("instances\\" + _name, "instance.toml", ss.str());
    }
}