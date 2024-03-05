#include <iostream>
#include "functions.h"
using namespace std;

void function_one(int& i, int& j) {
    // adds 1 to j, (after execution of the function, only j is changed)
    j += 1;
}

void function_two(struct example& foo) {
    // its integer by 1 (should persist after the function)
    foo.value += 1;
}

void function_three(int* k, int& l) {
    // TODO: implement function_three so that it increments both variables by one (both changes must
    // persist after the function call)
    *k += 1;
    l += 1;
}

void function_four(int** arr[], int size, int& lowest, int& highest) {
    // TODO: implement function_four so that it increments every value by two and then sets lowest /
    // highest to the min / max of the array (all changes must persist after the function call)
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            *arr[i][j] += 2;
        }
    }
    lowest = **arr[0];
    highest = **arr[0];
}