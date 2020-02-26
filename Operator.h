//
// Created by Macbook Pro on 26/02/2020.
//

#ifndef COMPILESTACK_OPERATOR_H
#define COMPILESTACK_OPERATOR_H


class Operator {
public:
    Operator() = default;
    Operator(char c);
    char getChar() const;
    int getPriority() const;
    int calculateOperation(int, int) const;
private:
    char c_;
    int priority_;
};


#endif //COMPILESTACK_OPERATOR_H
