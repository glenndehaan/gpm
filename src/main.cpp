#include "colors/colors.h"
#include "install/install.h"
#include <iostream>

// Define global variables
const std::string version = "v0.0.0";
const bool debug = true;

// Help fallback function
void help() {
    std::cout << "GPM (Glenn Package Manager) " << version << "\n";
    std::cout << "Usage: gpm [OPTIONS] install|remove pkg1 [pkg2 ...]\n\n";
    std::cout << "Option               Meaning\n";
    std::cout << "-h, --help           Shows this message\n";
}

// Main function
int main(int argc, char* argv[]) {
    if(debug) {
        std::cout << colorYellow << "!!!! WARNING: DEBUG ENABLED!!!!\n\n" << colorReset;
    }

    if(argc < 2) {
        help();
    } else {
        if(strcmp(argv[1], "-h") == 0 || strcmp(argv[1], "--help") == 0) {
            help();
            return 0;
        } else if(strcmp(argv[1], "install") == 0) {
            std::cout << "Checking registry for the following packages: ";
            for(int item = 2; item < argc; item++) {
                std::cout << colorGreen << argv[item] << colorReset;

                if((item + 1) == argc) {
                    std::cout << "\n";
                } else {
                    std::cout << ", ";
                }
            }

            for(int item = 2; item < argc; item++) {
                std::cout << "\n";
                std::cout << colorYellow << "Installing app " << (item - 1) << "/" << (argc - 2) << colorReset << "\n";
                installPackage(argv[item]);
            }
        } else if(strcmp(argv[1], "remove") == 0) {
            std::cout << "remove!\n";
        } else {
            help();
        }
    }
}
