#pragma once

#include <iostream>
#include <cmath>
#include <sstream>
#include "func.h"

using namespace std;

double operation(double a, double b, string &operation);

double calc(stack &queue, string &sign);

double getValue(stack &queue, string &sign);

double toDouble(string &item);


