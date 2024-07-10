#pragma once
#include <string>
#include <vector>

namespace LMC::FileSystem {
    void CreateFile(const std::string& subfolder, const std::string& filename, const std::string& content);
    void DeleteFolder(const std::string& subfolder);
    std::string GetFile(const std::string& subfolder, const std::string& filename);
    std::vector<std::string> GetFolders(const std::string& subfolder);
    inline std::string GetAppPath() { return std::string(std::getenv("APPDATA")) + "\\.lmc\\"; }
}