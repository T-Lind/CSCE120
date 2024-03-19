#include "functions.h"
#include <iostream>

using std::cout;
using std::endl;

#define INFO(X)  cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " = " << X << endl;
#define INFO_STRUCT(X) cout << "[INFO] ("<<__FUNCTION__<<":"<<__LINE__<<") " << #X << " count = " << X.count << endl;

/**
 * ----- REQUIRED -----
 * Pushes number to top of stack. If stack is full, then resize stack's array.
 * @param   stack   Target stack.
 * @param   number  Number to push to stack.
 */
void push(Stack &stack, int number) {
    INFO_STRUCT(stack)
    INFO(number)

    if (stack.count == stack.capacity) {
        int newCapacity = stack.capacity * 2;
        int *newNumbers = new int[newCapacity];
        for (int i = 0; i < stack.count; ++i) {
            newNumbers[i] = stack.numbers[i];
        }

        delete[] stack.numbers;

        stack.numbers = newNumbers;
        stack.capacity = newCapacity;
    }

    stack.numbers[stack.count] = number;
    stack.count++;
}

/**
 * ----- REQUIRED -----
 * Pops number from top of stack. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Value of popped number.
 */
int pop(Stack &stack) {
    INFO_STRUCT(stack)

    if (stack.count == 0) {
        return 2147483647;
    }

    int topElement = stack.numbers[stack.count - 1];

    stack.count--;

    return topElement;
}

/**
 * ----- REQUIRED -----
 * Returns the number at top of stack without popping it. If stack is empty, return INT32_MAX.
 * @param   stack   Target stack.
 * @return          Number at top of stack.
 */
int peek(const Stack &stack) {
    INFO_STRUCT(stack)

    if (stack.count == 0) {
        return 2147483647;
    }
    return stack.numbers[stack.count - 1];
}
