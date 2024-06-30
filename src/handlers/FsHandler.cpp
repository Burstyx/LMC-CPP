#include "handlers/FsHandler.h"

#include <filesystem>
#include <fstream>
#include <iostream>

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
