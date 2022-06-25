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

    stack notation = ShuntingYard::getNotation(line);
    cout << "notation: ";
    notation.show();

    string sign = notation.getElement();
    cout << "Result: " << endl << calc(notation, sign);

//    }
    return 0;
}
