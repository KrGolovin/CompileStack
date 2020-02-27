//
// Created by Macbook Pro on 19/02/2020.
//
#pragma once
#include <exception>
//======================================================================== // Классы StackOverflow и StackUnderflow представляют две основные
// исключительные ситуации, которые могут возникнуть при работе со стеком //========================================================================
class StackOverflow : public std::exception
{
public:
    StackOverflow() : reason("Stack Overflow") {}
    const char* what() const noexcept { return reason; }
private:
    const char* reason;  // ! const
};

class StackUnderflow : public std::exception
{
public:
    StackUnderflow() : reason("Stack Underflow") {}
    const char* what() const noexcept { return reason; }
private:
    const char* reason;  // ! const
};

class WrongStackSize : public std::exception {
public:
    WrongStackSize() : reason("Wrong Stack Size") {}

    const char *what() const noexcept { return reason; }

private:
    const char *reason;  // ! const
};

class UndefSymbol : public std::exception {
public:
    UndefSymbol() : reason("Undefinded symbol in input string") {}

    const char *what() const noexcept { return reason; }

private:
    const char *reason;  // ! const
};

class DivisionByZero : public std::exception {
public:
    DivisionByZero() : reason("Division by zero ") {}

    const char *what() const noexcept { return reason; }

private:
    const char *reason;  // ! const
};

class BracketsException : public std::exception {
public:
    BracketsException() : reason("Wrong count of brackets ") {}

    const char *what() const noexcept { return reason; }

private:
    const char *reason;  // ! const
};
