#pragma once

#include <iostream>
#include "stack.h"

using namespace  std;

class example {
    string line;

    static bool ifEnd(char symbol);

    bool isNegative(int index);

    static void add(stack &tokens, string &item);
public:
    example(const string &line);

    const string &getLine() const;

    void setLine(const string &line);

    stack getTokens();



};

