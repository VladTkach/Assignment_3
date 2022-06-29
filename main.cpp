#include "stack.h"
#include "ShuntingYard.h"
#include "LineProcessing.h"

int main(int size, char *arg[]) {
    string line = LineProcessing::getLine(size, arg);
    if (!line.empty()) {
        double result = ShuntingYard::getNotation(line);
        cout << "Result: " << result;
    }
    return 0;
}
