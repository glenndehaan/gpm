// http.cpp Header file
#include <iostream>
#include <string>
#include <curl/curl.h>

static size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
void getPackageInfo(std::string repoBaseUrl);