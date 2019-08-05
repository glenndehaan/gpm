#include "install.h"
#include "../colors/colors.h"
#include <iostream>

// Help fallback function
void installPackage(char* package) {
    std::cout << "[" << colorGreen << package << colorReset << "]" << " Using registry: \n";
}
