// http.cpp Header file
#include "../vendor/json.h"
#include <iostream>
#include <string>

using json = nlohmann::json;

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
json getPackageInfo(std::string repoBaseUrl, std::string package);
