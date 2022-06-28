#include "ShuntingYard.h"

double ShuntingYard::getNotation(string &line) {
    stack<double> test;
    stack<string> array;
    string current;
    for (int i = 0; i < line.length(); ++i) {
        ifUnary(i, line);
        current = line[i];
        if (isNumber(current)) {
            current = getNumber(i, line);
            double elem = toDouble(current);
            test.addElement(elem);
        } else if (isOpen(current)) {
            array.addElement(current);
        } else if (isClose(current)) {
            pushScope(array, test);
        } else {
            pushOperation(array, current, test);
        }
    }
    takeCashBack(array, test);
    double result = test.getElement();
    return result;
}

void ShuntingYard::pushOperation(stack<string> &array, string &current, stack<double> &test) {
    if (!array.isEmpty()) {
        string temp = array.getElement();
        if (getPrecedence(current) <= getPrecedence(temp) && !getAssociativity(current) ||
            getPrecedence(current) < getPrecedence(temp) && getAssociativity(current)) {
            addOperation(test, temp);
            array.deleteElement();
            if (getAssociativity(temp)) {
                while (!array.isEmpty()) {
                    temp = array.getElement();
                    if (!getAssociativity(temp)) {
                        break;
                    } else {
                        addOperation(test, temp);
                        array.deleteElement();
                    }
                }
            }
        }
    }
    array.addElement(current);
}


void ShuntingYard::takeCashBack(stack<string> &array, stack<double> &test) {
    while (!array.isEmpty()) {
        string current = array.getElement();
        addOperation(test, current);
        array.deleteElement();
    }
}

void ShuntingYard::pushScope(stack<string> &array, stack<double> &test) {
    while (!array.isEmpty()) {
        string current = array.getElement();
        if (current == "(") {
            array.deleteElement();
            break;
        } else {
            addOperation(test, current);
            array.deleteElement();
        }
    }
}

string ShuntingYard::getNumber(int &start, string &line) {
    string number;
    while (start < line.length()) {
        if (isNumber(line[start]) || line[start] == '.')
            number += line[start++];
        else
            break;
    }
    start--;
    return number;
}

void ShuntingYard::ifUnary(int index, string &line) {
    if (line[index] == '-' && (index == 0 || line[index - 1] <= 47 ||
                               line[index - 1] >= 58 || line[index + 1] >= 58)) {
        line[index] = 'm';
    }
}

void ShuntingYard::addOperation(stack<double> &test, string &oper) {
    double a, b;
    a = test.getElement();
    test.deleteElement();

    if (oper == "m"){
        b = 0;
    }
    else{
        b = test.getElement();
        test.deleteElement();
    }

    double res = operation(a, b, oper);
    test.addElement(res);
}

double ShuntingYard::operation(double a, double b, string &operation) {
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




