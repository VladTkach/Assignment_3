#pragma once

#include <iostream>

using namespace std;

class stack {
    int size;
    string *array;
    int maxSize;

public:
    stack();

    ~stack();

    void addElement(string&);

    string getElement();

    void deleteElement();

    void show();

    bool isEmpty();

    int getSize() const;

    void reverse();

    void resize();


};