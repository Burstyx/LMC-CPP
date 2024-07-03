#pragma once
#include <string>
#include <vector>

void createFile(const std::string& subfolder, const std::string& filename, const std::string& content);
std::string getFile(const std::string &subfolder, const std::string &filename);
std::vector<std::string> getFolders(const std::string &subfolder);