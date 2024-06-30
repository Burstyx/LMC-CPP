#include "handlers/FsHandler.h"

#include <filesystem>
#include <fstream>

void createFile(const std::string& subfolder, const std::string& filename, const std::string& content) {
    const std::string appdata = std::getenv("APPDATA");
    const std::string path = appdata + "/.lmc";
    const std::string filepath = path + "/" + subfolder + "/" + filename;

    std::filesystem::create_directories(path);

    const std::string fullpath = path + "/" + filepath;

    std::ofstream file(fullpath);
    file << content;
}
