#include "calc.h"

double calc::toDouble(string &item) {
    stringstream ss;
    ss << item;
    double res;
    ss >> res;
    return res;
}

double calc::operation(double a, double b, string &operation) {
    if (operation == "+") {
        return a + b;
    }
    if (operation == "-" || operation == "m") {
        return b - a;
    }
    if (operation == "*") {
        return a * b;
    }
    if (operation == "/") {
        return b / a;
    }
    if (operation == "^") {
        return pow(b, a);
    }
    return 0;
}
