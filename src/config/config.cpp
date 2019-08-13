#include "config.h"
#include "../colors/colors.h"
#include <iostream>
#include <fstream>
#include <queue>

// Global config
const std::string version = "v0.0.0";
const bool debug = true;

std::deque<std::string> registryConfig() {
    std::ifstream registryFile;
    registryFile.open("config/registry.list");
    if (registryFile.is_open()) {
        std::deque<std::string> registries;
        std::string line;
        while (getline(registryFile, line)) {
            if(line != "\n") {
                registries.push_back(line);
            }
        }
        registryFile.close();
        return registries;
    } else {
        std::cout << colorRed << "FATAL: Unable to open registry file!" << colorReset << "\n";
        exit(1);
    }
}
