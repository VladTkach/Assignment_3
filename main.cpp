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
    stack<string> notation = ShuntingYard::getNotation(line);
    if (notation.getSize() == 1) {
        cout << "Result: " << notation.getElement();
    } else {
        notation.show();
        string sign = notation.getElement();
        cout << "Result: " << calc(notation, sign);
    }
//    }
    return 0;
}
