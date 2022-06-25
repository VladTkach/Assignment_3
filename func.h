#pragma once

#include <iostream>
#include "stack.h"

using namespace std;

bool isNumber(string number);

bool isNumber(char number);

bool isOpen(string &token);

bool isClose(string &token);

int getPrecedence(string &token);

bool getAssociativity(string &token);
