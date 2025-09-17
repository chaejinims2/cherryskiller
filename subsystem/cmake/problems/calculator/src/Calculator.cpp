#include "Calculator.h"

int Calculator::Add(int a, int b) {
    return a + b;
}

int Calculator::Subtract(int a, int b) {
    return a - b;
}

int Calculator::Multiply(int a, int b) {
    return a * b;
}

double Calculator::Divide(int a, int b) {
    return static_cast<double>(a) / b;
}
