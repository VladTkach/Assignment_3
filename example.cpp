
#include "example.h"

example::example(const string &line) {
    this->line = line;
}

const string &example::getLine() const {
    return line;
}

void example::setLine(const string &line) {
    this->line = line;
}

stack example::getTokens() {
    stack tokens;
    string item;
    for (int i = 0; i < line.length(); ++i) {
        if (ifEnd(line[i]) && !isNegative(i)) {
            add(tokens, item);
            item = line[i];
            add(tokens, item);
        } else
            item += line[i];
    }
    add(tokens, item);
    return tokens;
}

bool example::ifEnd(char symbol) {
    if (symbol <= 47 || symbol >= 58) {
        return true;
    }
    return false;
}

bool example::isNegative(int i) {
    if (line[i] == '-' && i == 0 || line[i] == '-' && line[i - 1] == '(') {
        return true;
    }
    return false;
}

void example::add(stack &tokens, string &item){

    if (!item.empty()){
        tokens.addElement(item);
        item = "";
    }
}
