#include "calc.h"

double calc(stack &queue, string &sign) {
    queue.deleteElement();
    double a, b;
    a = getValue(queue, sign);
    b = getValue(queue, sign);
    return operation(a, b, sign);
}

double getValue(stack &queue, string &sign) {
    string current = queue.getElement();
    if (isNumber(current)) {
        queue.deleteElement();
        return toDouble(current);
    }
    return calc(queue, current);
}

double operation(double a, double b, string &operation) {
    if (operation == "+") {
        return a + b;
    }
    if (operation == "-") {
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

double toDouble(string &item) {
    stringstream ss;
    ss << item;
    double res;
    ss >> res;
    return res;
}