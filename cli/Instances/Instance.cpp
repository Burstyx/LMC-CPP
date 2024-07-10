#include "Instances/Instance.h"

#include <iostream>

#include "Core/FileSystem.h"

#include <sstream>
#include <toml++/toml.hpp>

namespace LMC {
    Instance::Instance(std::string name, std::string version, std::string loader): m_Name(std::move(name)), m_Version(std::move(version)), m_Loader(std::move(loader)) { }

    Instance::Instance(const std::string &path) {
        toml::table rootTable = toml::parse_file(path + "\\instance.toml");

        const auto instanceTable = rootTable["instance"].as_table();
        m_Name = instanceTable->get("name")->value_or("unknown");
        m_TimePlayed = instanceTable->get("timePlayed")->value_or(0);
        m_LastPlayed = instanceTable->get("lastPlayed")->value_or(0);

        const auto mcTable = rootTable["minecraft"].as_table();
        m_Version = mcTable->get("instance")->value_or("latest");
        m_Loader = mcTable->get("loader")->value_or("vanilla");
    }

    void Instance::SaveToFile() const {
        toml::table instanceTable;
        instanceTable.insert_or_assign("name", m_Name);
        instanceTable.insert_or_assign("timePlayed", m_TimePlayed);
        instanceTable.insert_or_assign("lastPlayed", m_LastPlayed);

        toml::table mcTable;
        mcTable.insert_or_assign("instance", m_Version);
        mcTable.insert_or_assign("loader", m_Loader);

        toml::table rootTable;
        rootTable.insert_or_assign("instance", instanceTable);
        rootTable.insert_or_assign("minecraft", mcTable);

        std::stringstream ss;
        ss << rootTable;

        FileSystem::CreateFile("instances\\" + m_Name, "instance.toml", ss.str());
    }

    void Instance::DeleteFile() const {
        FileSystem::DeleteFolder("instances\\" + m_Name);
    }

    Instance Instance::GetInstanceFromName(const std::string &name) {
        return Instance(FileSystem::GetAppPath() + "instances\\" + name);
    }
}
