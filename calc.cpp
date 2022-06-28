#include "calc.h"

double calc(stack<string> &queue, string &sign) {
    queue.deleteElement();
    double a, b;

    a = getValue(queue, sign);
    if (sign == "m"){
        return operation(a, 0, sign);
    }
    b = getValue(queue, sign);
    return operation(a, b, sign);
}

double getValue(stack<string> &queue, string &sign) {
    if (!queue.isEmpty()) {
        string current = queue.getElement();
        if (isNumber(current)) {
            queue.deleteElement();
            return toDouble(current);
        }
        return calc(queue, current);
    }
    return 0;
}

double operation(double a, double b, string &operation) {
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

double toDouble(string &item) {
    stringstream ss;
    ss << item;
    double res;
    ss >> res;
    return res;
}