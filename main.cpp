#include "stack.h"
#include "calc.h"
#include "example.h"
#include "station.h"

int main(int size, char *arg[]) {
    string line;
    for (int i = 1; i < size; ++i) {
        line += arg[i];
    }
    if (!line.empty()) {
        example example(line);
        stack tokens = example.getTokens();

        stack details = station::getQueue(tokens);
        string sign = details.getElement();
        cout << "Result: " << calc(details, sign);

    }
    return 0;
}
