#include <iostream>
#include "functions.h"

using std::cout, std::cin, std::endl;

int main() {
    cout << "Enter numbers 10 <= a <= b < 10000: " << endl;
    int a, b;


    cin >> a >> b;
    while (!is_valid_range(a, b)) {
        cout << "Invalid input" << endl;
        cout << "Enter numbers 10 <= a <= b < 10000: " << endl;
        cin >> a >> b;
    }

    count_valid_mv_numbers(a, b);

	return 0;
}