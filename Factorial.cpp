#include <iostream>

/*
 * Prompt user for an integer, print the factorial of the number.
 * Verify user input is b/w 1 and 15. Keep prompting user until user enters input within range.
 */

int factorial(int n) {
    // Yes, I'm using recursion. I have plenty of experience with CS (6+ years atp)
    if (n == 0) {
        return 1;
    }
    return n * factorial(n - 1);
}


int main() {
    using namespace std;
    int n;

    do {
        cout << "Enter an integer: ";
        cin >> n;
    } while (n < 1 || n > 15);

    // n is now guaranteed to be b/w 1 and 15

    cout << "The factorial of " << n << " is " << factorial(n) << endl;
}