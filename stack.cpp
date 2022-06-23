#include "stack.h"

stack::stack() {
    size = 0;
    maxSize = 1;
    array = new string[maxSize];
}

stack::~stack() {
    delete[] array;
}

void stack::addElement(string &elem) {
    if (size + 1 > maxSize){
        resize();
    }
    array[size] = elem;
    size++;
}

string stack::getElement() {
    return array[size - 1];
}

void stack::deleteElement() {
    if (!isEmpty()){
        size--;
    }
}

bool stack::isEmpty() {
    if (size == 0){
        return true;
    }
    return false;
}

int stack::getSize() const {
    return size;
}

void stack::show() {
    for (int i = 0; i < size; ++i) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void stack::reverse() {
    auto *new_array = new string[maxSize];
    for (int i = 0; i < size; ++i) {
        new_array[i] = array[size - 1 - i];
    }
    delete[] array;
    array = new_array;
}

void stack::resize() {
    maxSize *= 2;
    string *new_array = new string[maxSize];
    for (int i = 0; i < size; ++i) {
        new_array[i] = array[i];
    }
    delete[] array;
    array = new_array;

}
