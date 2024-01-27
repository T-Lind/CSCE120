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

char classify_mv_range_type(int number) {
    // TODO(student): return 'M' if number has /\/\... pattern,
    // return 'V' if number has \/\/ pattern, and return 'N' otherwise
    int thousands = number / 1000;
    int hundreds = (number / 100) % 10;
    int tens = (number / 10) % 10;
    int ones = number % 10;

    // number isn't necessarily 4 digits.
    /*
     * An n-digit integer, for n >= 2, with digits d1d2d3d4…dn models:
     * a mountain range if it has the pattern /\/..., that is, d1 < d2  d2,> d3, d3 < d4, etc.
     * a valley range if it has the pattern \/\..., that is d1 > d2, d2 < d3, d3 > d4, etc.
     */

    if (thousands > 0) {
        if (thousands > hundreds && hundreds < tens && tens > ones) {
            return 'V';

        } else if (thousands < hundreds && hundreds > tens && tens < ones) {
            return 'M';
        }
    }
    else if (hundreds > 0) {
        if (hundreds > tens && tens < ones) {
            return 'V';
        } else if (ones < tens && tens > hundreds) {
            return 'M';
        }
    }
    else if (tens > 0) {
        if (tens > ones) {
            return 'V';
        } else if (tens < ones) {
            return 'M';
        }
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
    cout << "There are " << mountainCount << " mountain ranges, " << valleyCount << " valley ranges between " << a
         << " and " << b << endl;
}