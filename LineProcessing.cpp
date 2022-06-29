#include "LineProcessing.h"

string LineProcessing::getLine(int size, char **arg) {
    string line;
    for (int i = 1; i < size; ++i) {
        line += arg[i];
    }
    return line;
}
