//
// Created by Macbook Pro on 26/02/2020.
//

#include "functions.h"
#include "StackArray.h"
#include "Operator.h"
#include <sstream>
#include "exceptions.h"
bool isDigit(char c) {
    return (c >= '0') && (c <= '9');
}

void pushOperand(Operator & anOperator, StackArray<Operator> & stack, std::stringstream & ss) {
    if (anOperator.getChar() == '(') {
        stack.push(anOperator);
    } else {
        while (!stack.isEmpty() && stack.getTop().getPriority() >= anOperator.getPriority()) {
            ss << stack.pop().getChar();
        }
        if (anOperator.getChar() == ')') {
            if (stack.isEmpty() || stack.getTop().getChar() != '(') {
                throw BracketsException();
            }
            stack.pop();
        } else {
            stack.push(anOperator);
        }
    }
}

std::string toPostfix(std::string &input) {
    StackArray<Operator> stack(input.length());
    std::stringstream ss;
    for (char c: input) {
        if (isDigit(c)) {
            ss << c;
        } else {
            Operator op(c);
            pushOperand(op, stack, ss);
        }
    }
    while (!stack.isEmpty()) {
        if (stack.getTop().getChar() == '(') {
            throw BracketsException();
        }
        ss << stack.pop().getChar();
    }
    std::string ans = ss.str();
    return ans;
}

int calculate(std::string &input) {
    StackArray<int> stack(input.length());
    for (char c: input) {
        if (isDigit(c)) {
            stack.push(c - '0');
        } else {
            Operator op(c);
            stack.push(op.calculateOperation(stack.pop(), stack.pop()));
        }
    }
    return stack.pop();
}


