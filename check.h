#pragma once

#include <iostream>
#include "stack.h"

using namespace std;
class check{
public:
    static bool isNumber(string number);

    static bool isNumber(char number);

    static  bool isOpen(string &token);

    static  bool isClose(string &token);

    static int getPrecedence(string &token);

    static bool getAssociativity(string &token);

    static void ifUnary(int index, string &line);
};