#include "func.h"

bool isNumber(string number) {
    return (number.length() == 1 && number[0] > 47 && number[0] < 58);
}

bool isNumber(char number) {
    return number > 47 && number < 58;
}

bool isOpen(string &token) {
    return token == "(";
}

bool isClose(string &token) {
    return token == ")";
}

int getPrecedence(string &token) {
    if (token == "+" || token == "-") {
        return 1;
    }
    if (token == "*" || token == "/") {
        return 2;
    }
    if (token == "^" || token == "m") {
        return 3;
    }
    if (token == "(") {
        return 0;
    }
    return 0;
}

bool getAssociativity(string &token) {

    if (token == "^" || token == "m") {
        return true;
    }
    return false;
}