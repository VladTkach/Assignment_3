#pragma once

#include <iostream>
#include "stack.h"
#include "func.h"

using namespace std;

class ShuntingYard {
    static void pushScope(stack &array, stack &queue);

    static void pushOperation(stack &array, stack &queue, string &current);

    static void takeCashBack(stack &array, stack &queue);

    static string getNumber(int &start, string &line);

public:
    static stack getNotation(string &line);

};
