#include "http.h"
#include "../colors/colors.h"
#include "../vendor/HTTPRequest.h"
#include "../vendor/json.h"
#include <iostream>
#include <string>

using json = nlohmann::json;

// HTTP Request to get package info
json getPackageInfo(std::string repoBaseUrl, std::string package) {
    try {
        // Build URL
        std::string url = repoBaseUrl + "?package=" + package;

        // Setup request
        http::Request request(url);

        // Send a GET request
        http::Response response = request.send("GET");

        // Parse json
        json j = json::parse(std::string(response.body.begin(), response.body.end()));

        // Check if result is OKE
        if(j["status"] == 200) {
            j["package"]["found"] = true;
            return j["package"];
        }

        j["package"]["found"] = false;
        return j["package"];
    } catch(...) {
        json j = {
            {"found", false}
        };
        std::cout << colorRed << "[ERROR] Registry Error! Invalid response!" << colorReset << "\n";
        return j;
    }
}
