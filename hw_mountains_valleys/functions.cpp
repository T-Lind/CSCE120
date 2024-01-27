#include <iostream>
#include "functions.h"

using std::cout, std::endl;

bool is_valid_range(int a, int b) {
    if (a > b) {
        return false;
    }
    if (a < 10 || a > 9999 || b < 10 || b > 9999) {
        return false;
    }

    return true;
}
/*
 * Helper function for computing powers
 */
double pow(double base, int exponent) {
    double result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

char classify_mv_range_type(int number) {
    int temp = number;
    int numLength = 0;
    while (temp >= 10) {
        temp /= 10;
        numLength++;
    }
    // yes this is super inefficient, but it's the first solution I thought of okay
    bool valley = true;
    bool mountain = true;
    int currentDigit;
    int nextDigit;
    int currentNum = number;
    for (int i = 0; i < numLength; i++) {
        currentDigit = currentNum / (int) pow(10, numLength - i);
        nextDigit = (currentNum / (int) pow(10, numLength - i - 1)) % 10;
        currentNum -= currentDigit * (int) pow(10, numLength - i);
        if (i % 2 == 0) {
            if (currentDigit <= nextDigit) {
                valley = false;
            }
            if (currentDigit >= nextDigit) {
                mountain = false;
            }
        } else {
            if (currentDigit >= nextDigit) {
                valley = false;
            }
            if (currentDigit <= nextDigit) {
                mountain = false;
            }
        }
    }
    if (valley) {
        return 'V';
    }
    if (mountain) {
        return 'M';
    }


    return 'N';

}

void count_valid_mv_numbers(int a, int b) {
    // ranges in the range [a, b] and print out to console using the format
    // in Requirement 4 of the homework prompt
    int mountainCount = 0;
    int valleyCount = 0;

    for (int i = a; i <= b; i++) {
        char type = classify_mv_range_type(i);
        if (type == 'M') {
            mountainCount++;
        } else if (type == 'V') {
            valleyCount++;
        }
    }
    cout << "There are " << mountainCount << " mountain ranges and " << valleyCount << " valley ranges between " << a
         << " and " << b << "." << endl;
}