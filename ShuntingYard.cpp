#include "ShuntingYard.h"

stack ShuntingYard::getNotation(string &line) {
    stack queue;
    stack array;
    string current;
    for (int i = 0; i < line.length(); ++i) {
        current = line[i];
        if (isNumber(current)) {
            current = getNumber(i, line);
            queue.addElement(current);
        } else if (isOpen(current)) {
            array.addElement(current);
        } else if (isClose(current)) {
            pushScope(array, queue);
        } else {
            pushOperation(array, queue, current);
        }
    }

    takeCashBack(array, queue);
    return queue;
}

void ShuntingYard::pushOperation(stack &array, stack &queue, string &current) {
    if (!array.isEmpty()) {
        string temp = array.getElement();
        if (getPrecedence(current) <= getPrecedence(temp) && !getAssociativity(current) ||
            getPrecedence(current) < getPrecedence(temp) && getAssociativity(current)) {
            queue.addElement(temp);
            array.deleteElement();
        }
    }
    array.addElement(current);
}


void ShuntingYard::takeCashBack(stack &array, stack &queue) {
    while (!array.isEmpty()) {
        string current = array.getElement();
        queue.addElement(current);
        array.deleteElement();
    }
}

void ShuntingYard::pushScope(stack &array, stack &queue) {
    while (!array.isEmpty()) {
        string current = array.getElement();
        if (current == "(") {
            array.deleteElement();
            break;
        } else {
            queue.addElement(current);
            array.deleteElement();
        }
    }
}

string ShuntingYard::getNumber(int &start, string &line) {
    string number;
    while (start < line.length()) {
        if (isNumber(line[start])){
            number += line[start];
            start++;
        }
        else{
            break;
        }
    }
    start--;
    return number;
}




