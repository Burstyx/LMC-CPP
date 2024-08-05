#pragma once

#include <string>

namespace LMC::HTTPRequest {
    std::string Get(const std::string& url);
    std::string Post(const std::string& url, const std::string& data);
    void Download(const std::string& url, const std::string& path);
}