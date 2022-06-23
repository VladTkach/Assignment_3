#include "station.h"

stack station::getQueue(stack &token) {
    token.reverse();
    stack queue;
    stack array;
    while (!token.isEmpty()) {
        string current = token.getElement();
        if (isNumber(current)){
            queue.addElement(current);
        }
        else if(isOpen(current)){
            array.addElement(current);
        }
        else if (isClose(current)){
            pushScope(array, queue);
        }
        else if(getAssociativity(current)){
            pushOperation(array, queue, current);
        }
        else{
            pushOperation2(array, queue, current);
        }
        token.deleteElement();
    }

    takeCashBack(array, queue);

    return queue;
}

void station::pushOperation(stack &array, stack &queue, string &current){
    if (!array.isEmpty()) {
        string temp = array.getElement();
        if (getPrecedence(current) < getPrecedence(temp)) {
            queue.addElement(temp);
            array.deleteElement();
        }
    }
    array.addElement(current);
}

void station::pushOperation2(stack &array, stack &queue, string &current){
    if (!array.isEmpty()) {
        string temp = array.getElement();
        if (getPrecedence(current) <= getPrecedence(temp)) {
            queue.addElement(temp);
            array.deleteElement();
        }
    }
    array.addElement(current);
}

void station::takeCashBack(stack &array, stack &queue){
    while (!array.isEmpty()){
        string current = array.getElement();
        queue.addElement(current);
        array.deleteElement();
    }
}

void station::pushScope(stack &array, stack &queue){
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


