//
// Created by Macbook Pro on 26/02/2020.
//

#include "functions.h"
#include "StackArray.h"
#include "Operator.h"
bool isDigit(char c) {
    return (c > '0') && (c < '9');
}

void pushOperand(Operator & anOperator, StackArray<Operator> & stack) {
    if (anOperator.getChar() == '(') {
        stack.push(anOperator);
    } else {
        while (!stack.isEmpty() && stack.getTop().getPriority() >= anOperator.getPriority()) {
            std::cout << stack.pop().getChar();
        }
        if (anOperator.getChar() == ')') {
            stack.pop();
        } else {
            stack.push(anOperator);
        }
    }
}

void toPostfix(std::string &input) {
    StackArray<Operator> stack(input.length());
    for (char c: input) {
        Operator op(c);
        if (isDigit(c)) {
            std::cout << c;
        } else {
            pushOperand(op, stack);
        }
    }
    while (!stack.isEmpty()) {
        std::cout << stack.pop().getChar();
    }
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


