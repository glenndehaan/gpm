#include <iostream>

std::string version = "v0.0.0";

void help() {
    std::cout << "GPM (Glenn Package Manager) ";
    std::cout << version;
    std::cout << "\n";
    std::cout << "Usage: gpm [OPTIONS] install|remove pkg1 [pkg2 ...]\n\n";
    std::cout << "Option               Meaning\n";
    std::cout << "-h, --help           Shows this message\n";
}

int main(int argc, char* argv[]) {
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
