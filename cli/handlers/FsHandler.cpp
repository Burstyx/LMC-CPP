#include <handlers/FsHandler.h>

#include <filesystem>
#include <fstream>
#include <iostream>
#include <vector>

void createFile(const std::string& subfolder, const std::string& filename, const std::string& content) {
    const std::string appdata = std::getenv("APPDATA");
    const std::string path = appdata + "\\.lmc\\" + subfolder;

    const std::string fullpath = path + "\\" + filename;

    std::filesystem::create_directories(path);

    if(std::ofstream file(fullpath); file.is_open()) {
        file << content;
        file.close();
    } else {
        std::cerr << "Unable to open file for writing: " << fullpath << std::endl;
    }
}

std::string getFile(const std::string &subfolder, const std::string &filename) {
    const std::string appdata = std::getenv("APPDATA");
    const std::string path = appdata + "\\.lmc\\" + subfolder;

    const std::string fullpath = path + "\\" + filename;

    if(std::ifstream fileStream(fullpath); fileStream.is_open()) {
        std::stringstream buffer;
        buffer << fileStream.rdbuf();

        fileStream.close();

        return buffer.str();
    }

    return "";
}

std::vector<std::string> getFolders(const std::string &subfolder) {
    const std::string appdata = std::getenv("APPDATA");
    const std::string path = appdata + "\\.lmc\\" + subfolder;

    std::vector<std::string> folders;

    for (const auto &entry : std::filesystem::directory_iterator(path)) {
        if (entry.is_directory()) {
            folders.push_back(entry.path().string());
        }
    }

    return folders;
}