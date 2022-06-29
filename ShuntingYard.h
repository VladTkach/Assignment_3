#pragma once

#include <iostream>
#include "stack.h"
#include "check.h"
#include "calc.h"

using namespace std;

class ShuntingYard {
    static void pushScope(stack<string> &array, stack<double > &test);

    static void pushOperation(stack<string> &array, string &current, stack<double > &test);

    static void takeCashBack(stack<string> &array, stack<double > &test);

    static string getNumber(int &start, string &line);

    static void addOperation(stack<double> &test, string &oper);

public:
    static double getNotation(string &line);


};
