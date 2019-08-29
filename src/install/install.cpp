#include "install.h"
#include "../config/config.h"
#include "../colors/colors.h"
#include "../http/http.h"
#include "../vendor/json.h"
#include <iostream>
#include <time.h>

using json = nlohmann::json;

// Install package function
void installPackage(char* package) {
    std::deque<std::string> registries = registryConfig();

    for(int item = 0; item < registries.size(); item++) {
        json packageInfo = getPackageInfo(registries[item], package);
        if(!packageInfo["found"]) {
            std::cout << "[" << colorGreen << package << colorReset << "]" << " Using registry: "<< registries[item] << " \n";
            std::cout << "[" << colorGreen << package << colorReset << "]" << colorRed << " Package not found!" << colorReset << "\n\n";
            sleep(1000);
        } else {
            std::cout << "[" << colorGreen << package << colorReset << "]" << " Using registry: "<< registries[item] << " \n";
            std::cout << "[" << colorGreen << package << colorReset << "]" << " Found version: " << std::string(packageInfo["version"]) << "\n";
            sleep(2500);
            std::cout << "[" << colorGreen << package << colorReset << "]" << " Unpacking...\n";
            sleep(1000);
            std::cout << "[" << colorGreen << package << colorReset << "]" << " Creating bin links...\n";
            sleep(1000);
            std::cout << "[" << colorGreen << package << colorReset << "]" << " Copying files...\n";
            sleep(1000);
            std::cout << "[" << colorGreen << package << colorReset << "]" << " Cleaning up...\n";
            sleep(1000);
            std::cout << "[" << colorGreen << package << colorReset << "]" << " Installation complete!\n\n";
            break;
        }
    }
}

// Temp sleep function
void sleep(int milisec) {
    struct timespec req = {milisec/1000, milisec%1000 * 1000000L};
    nanosleep(&req, NULL);
}
