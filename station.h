#pragma once

#include <iostream>
#include "stack.h"
#include "func.h"

using namespace std;

class station {
    static void pushScope(stack &array, stack &queue);

    static void pushOperation(stack &array, stack &queue, string &current);

    static void pushOperation2(stack &array, stack &queue, string &current);

    static void takeCashBack(stack &array, stack &queue);


public:
    static stack getQueue(stack &token);
};
