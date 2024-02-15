#include <iostream>
#include <limits>
#include <cstdlib>
int count_of_elements(int *A, int length, int a, int b);

using namespace std;

void check_input(int a, int b){
    if (a >= b)
    {
        throw invalid_argument("a must be less than b");
    }
    // Otherwise we're good and we don't need to do anything
}



int main () {
    srand(20);
    const int SIZE = 1000;
    int A[SIZE];
    for (int i = 0; i < SIZE; i++){
        A[i] = rand() % 100;
    }

    int a;
    int b;

    while (true){
        cout << "Enter a range, a to b: ";
        cin >> a >> b;
        try {
            // make sure input is okay
            check_input(a, b);
            break;
        } catch (const invalid_argument& err) {
            // Only catch invalid argument for good coding practicies
            cout << "Invalid input. Try again." << endl;
        }
    }

    cout << "Number of elements between " << a << " and " << b << " is : " << count_of_elements(A, SIZE, a, b) << endl;
}


int count_of_elements(int *A, int length, int a, int b){
    int count = 0;
    for (int i = 0; i < length; i++){
        if ((A[i] >= a) && (A[i] <= b) )
            count++;
    }
    return count;
}