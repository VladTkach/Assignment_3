#pragma once

#include <iostream>

using namespace std;

template<typename T>
class stack {
    int size;
    T *array;
    int maxSize;

public:
    stack() {
        size = 0;
        maxSize = 1;
        array = new T[maxSize];
    };

    ~stack() {
        delete[] array;
    };

    void addElement(T& elem) {
        if (size + 1 > maxSize) {
            resize();
        }
        array[size] = elem;
        size++;
    };

    T getElement() {
        return array[size - 1];
    };

    void deleteElement() {
        if (!isEmpty()) {
            size--;
        }
    };

    void show(){
        for (int i = 0; i < size; ++i) {
            cout << array[i] << " ";
        }
        cout << endl;
    };

    bool isEmpty(){
        return (size == 0);
    };

    int getSize() const{
        return size;
    };

    void resize(){
        maxSize *= 2;
        T *new_array = new T[maxSize];
        for (int i = 0; i < size; ++i) {
            new_array[i] = array[i];
        }
        delete[] array;
        array = new_array;

    };


};