#include <iostream>
#include "functions.h"

int main() {
    std::string str = "(((3+7))*(2-1))";
    std::string str2 = "37+21+*";
    toPostfix(str);
    std::cout << std::endl;
    std::cout << calculate(str2);
    //std::cout << "Hello, World!" << std::endl;
    return 0;
}
