#pragma once

#include <string>

namespace LMC::HTTPRequest {
    std::string Get(const std::string& url);
    std::string Post(const std::string& url, const std::string& data);
    size_t WriteData(const void *ptr, size_t size, size_t nmemb, void *stream);
    void Download(const std::string& url, const std::string& path);
}