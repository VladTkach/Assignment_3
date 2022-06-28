#pragma once

#include <iostream>
#include "stack.h"
#include "func.h"

using namespace std;

class ShuntingYard {
    static void pushScope(stack<string> &array, stack<string> &queue);

    static void pushOperation(stack<string> &array, stack<string> &queue, string &current);

    static void takeCashBack(stack<string> &array, stack<string> &queue);

    static string getNumber(int &start, string &line);

    static void ifUnary(int index, string &line);

public:
    static stack<string> getNotation(string &line);

};
