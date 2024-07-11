#include "Core/HTTPRequest.h"

#include <curl/curl.h>

namespace LMC::HTTPRequest {
    size_t WriteData(const void *ptr, const size_t size, const size_t nmemb, void *stream) {
        const size_t written = fwrite(ptr, size, nmemb, static_cast<FILE *>(stream));
        return written;
    }

    void Download(const std::string &url, const std::string &path) {
        if (CURL *curl = curl_easy_init()) {
            FILE *fp = fopen(path.c_str(), "wb");
            curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
            curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteData);
            curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
            curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1L);

            if (const CURLcode res = curl_easy_perform(curl); res != CURLE_OK)
                fprintf(stderr, "curl_easy_perform() failed: %s\n",
                        curl_easy_strerror(res));

            fclose(fp);
            curl_easy_cleanup(curl);
        }
    }
}