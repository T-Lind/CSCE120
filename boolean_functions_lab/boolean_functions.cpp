#include <iostream>
#include "boolean_functions.h"

using std::cin, std::cout, std::endl, std::boolalpha;

void printNOT() {
    cout << "--- print NOT ---" << endl;

    cout << " x | NOT x" << endl;
    cout << "---+-------" << endl;
    cout << " 0 |   1" << endl;
    cout << " 1 |   0" << endl;

    cout << endl;
}

void printOR() {
    cout << "--- print OR ---" << endl;

    cout << " x | y | x OR y" << endl;
    cout << "---+---+--------" << endl;
    cout << " 0 | 0 |   0" << endl;
    cout << " 0 | 1 |   1" << endl;
    cout << " 1 | 0 |   1" << endl;
    cout << " 1 | 1 |   1" << endl;

    cout << endl;
}

void printAND() {
    cout << "--- print AND ---" << endl;

    cout << " x | y | x AND y" << endl;
    cout << "---+---+---------" << endl;
    cout << " 0 | 0 |    0" << endl;
    cout << " 0 | 1 |    0" << endl;
    cout << " 1 | 0 |    0" << endl;
    cout << " 1 | 1 |    1" << endl;

    cout << endl;
}

void printXOR() {
    cout << "--- print XOR ---" << endl;

    cout << " x | y | x XOR y" << endl;
    cout << "---+---+---------" << endl;
    cout << " 0 | 0 |    0" << endl;
    cout << " 0 | 1 |    1" << endl;
    cout << " 1 | 0 |    1" << endl;
    cout << " 1 | 1 |    0" << endl;

    cout << endl;
}

bool booleanLogic1(bool x, bool y, bool z) {
    cout << "--- Boolean Logic 1 ---" << endl;

    bool value = x || y || z;

    cout << boolalpha << x << " OR " << y << " OR " << z << " = " << value << endl;

    cout << endl;
    return value;
}

bool booleanLogic2(bool x, bool y, bool z) {
    cout << "--- Boolean Logic 2 ---" << endl;

    bool value = x && y && z;

    cout << boolalpha << x << " AND " << y << " AND " << z << " = " << value << endl;

    cout << endl;
    return value;
}

bool booleanLogic3(bool x, bool y, bool z) {
    cout << "--- Boolean Logic 3 ---" << endl;

    bool value = x ^ y ^ z;
    cout << boolalpha << x << " XOR " << y << " XOR " << z << " = " << value << endl;

    cout << endl;
    return value;
}

// this function counts the letters in str
unsigned int countLetters(std::string str) {
    cout << "--- count Letters ---" << endl;

    unsigned int count = 0;
    for (char letter: str) {
        if (isalpha(letter)) {
            count++;
        }
    }
    return count;
}

bool f(bool x, bool y, bool z) {
    cout << "--- f ---" << endl;

    bool boolVal = (x && !y && !z) || (!x && y) || (!x && z) || (y && z);
    // include parentheses in print statement to make the order of operations clear
    cout << boolalpha << "(" << x << " AND NOT " << y << " AND NOT " << z << ") OR (NOT " << x << " AND " << y
         << ") OR (NOT " << x << " AND " << z << ") OR (" << y << " AND " << z << ") = " << boolVal << endl;

    return boolVal;
}

void setAssignments(bool &w, bool &x, bool &y, bool &z)
// You'll learn what the & means in the function signature later this semester
// You don't need to calculate the value
{
    cout << "--- set Assignments ---" << endl;

    w = true;
    x = true;
    y = false;
    z = false;

    // todo: figure out why this isn't a good answer
}



