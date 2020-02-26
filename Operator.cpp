//
// Created by Macbook Pro on 26/02/2020.
//

#include "Operator.h"
#include <algorithm>
#include "exceptions.h"
char Operator::getChar() const {
    return c_;
}

Operator::Operator(char c): c_(c) {
    switch (c) {
        case '(':
            priority_ = 0;
            break;
        case ')':
            priority_ = 1;
            break;
        case '+':
        case '-':
            priority_ = 2;
            break;
        case '*' :
        case '/':
            priority_ = 3;
            break;
        default:
            throw UndefSymbol();
    }
}

int Operator::getPriority() const {
    return priority_;
}

int Operator::calculateOperation(int first, int second) const {
    std::swap(first, second);
    switch (c_) {
        case '+':
            return first + second;
        case '-':
            return first - second;
        case '*':
            return first * second;
        case '/':
            return first / second;
    }
}
