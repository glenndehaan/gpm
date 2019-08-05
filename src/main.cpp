#include <iostream>

// Define global variables
std::string version = "v0.0.0";
bool debug = true;

// Define colors
const std::string colorRed("\033[0;31m");
const std::string colorGreen("\033[0;32m");
const std::string colorYellow("\033[0;33m");
const std::string colorBlue("\033[0;34m");
const std::string colorMagenta("\033[0;35m");
const std::string colorCyan("\033[0;36m");
const std::string colorWhite("\033[0;37m");
const std::string colorReset("\033[0m");

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
            std::cout << "install!\n";
        } else if(strcmp(argv[1], "remove") == 0) {
            std::cout << "remove!\n";
        } else {
            help();
        }
    }
}
