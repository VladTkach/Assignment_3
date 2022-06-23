#include "func.h"

bool isNumber(string number){
    if (number.length() == 1 && number[0] <= 47 || number[0] >= 58 ){
        return false;
    }
    return true;

}

bool isOpen(string &token){
    if (token == "("){
        return true;
    }
    return false;
}

bool isClose(string &token){
    if (token == ")"){
        return true;
    }
    return false;
}

int getPrecedence(string &token) {
    if (token == "+" || token == "-") {
        return 1;
    }
    if (token == "*" || token == "/") {
        return 2;
    }
    if (token == "^") {
        return 3;
    }
    if (token == "(") {
        return 0;
    }
    return 0;
}

bool getAssociativity(string &token) {

    if (token == "^") {
        return true;
    }
    return false;
}