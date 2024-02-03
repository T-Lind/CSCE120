#include <iostream>
#define LENGTH 5

int main() {
    using namespace std;

    int arr[LENGTH] = {1, 2, 3, 4, 5};

    int sum = 0;
    for (int i : arr) {
        sum += i;
    }

    cout << "Sum: " << sum << endl;
}