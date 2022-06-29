#include "check.h"

bool check::isNumber(string number) {
    return (number[0] > 47 && number[0] < 58);
}

bool check::isNumber(char number) {
    return number > 47 && number < 58;
}

bool check::isOpen(string &token) {
    return token == "(";
}

bool check::isClose(string &token) {
    return token == ")";
}

int check::getPrecedence(string &token) {
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

bool check::getAssociativity(string &token) {
    return token == "^" || token == "m";
}

void check::ifUnary(int index, string &line) {
    if (line[index] == '-' && (index == 0 || line[index - 1] <= 47 ||
                               line[index - 1] >= 58 || line[index + 1] >= 58)) {
        line[index] = 'm';
    }
}