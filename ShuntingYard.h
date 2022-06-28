#pragma once

#include <iostream>
#include "stack.h"
#include "func.h"
#include "calc.h"

using namespace std;

class ShuntingYard {
    static void pushScope(stack<string> &array, stack<double > &test);

    static void pushOperation(stack<string> &array, string &current, stack<double > &test);

    static void takeCashBack(stack<string> &array, stack<double > &test);

    static string getNumber(int &start, string &line);

    static void ifUnary(int index, string &line);

    static double operation(double a, double b, string &operation);

public:
    static double getNotation(string &line);

    static void addOperation(stack<double> &test, string &oper);
};
