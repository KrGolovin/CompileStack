#include <iostream>
#include "functions.h"

int main() {
    try {
        std::string str = "(((3+7))*(2+1))";
        std::cout << toPostfix(str);
    } catch(std::exception & e) {
        std::cerr << e.what() << std::endl;
    }
    try {
        std::string str2 = "37+21+*";
        std::cout << std::endl << calculate(str2);
    } catch(std::exception & e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
