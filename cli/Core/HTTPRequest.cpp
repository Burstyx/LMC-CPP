#include "Core/HTTPRequest.h"
#include "httplib.h"

namespace LMC::HTTPRequest {
    void Download(const std::string &url, const std::string &path) {
        httplib::Client client(url);

        if (auto res = client.Get("/")) {
            std::ofstream file(path, std::ios::binary);
            file.write(res->body.c_str(), res->body.size());
            file.close();
        }
    }
}