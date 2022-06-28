#include "stack.h"
#include "calc.h"
#include "ShuntingYard.h"

int main(int size, char *arg[]) {
    string line;
//    for (int i = 1; i < size; ++i) {
//        line += arg[i];
//    }
//    if (!line.empty()) {
    getline(cin, line);
    double result;
    result = ShuntingYard::getNotation(line);
    cout << "Result: " << result;
//    }
    return 0;
}
