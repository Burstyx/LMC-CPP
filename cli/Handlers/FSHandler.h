#pragma once
#include <string>
#include <vector>

namespace LMC {
    void CreateFile(const std::string& subfolder, const std::string& filename, const std::string& content);
    std::string GetFile(const std::string& subfolder, const std::string& filename);
    std::vector<std::string> GetFolders(const std::string& subfolder);
}