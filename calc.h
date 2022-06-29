#pragma once

#include <iostream>
#include <cmath>
#include <sstream>
#include "check.h"

using namespace std;

class calc{
public:
    static double operation(double a, double b, string &operation);

    static double toDouble(string &item);
};






