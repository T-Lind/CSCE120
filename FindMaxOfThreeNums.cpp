#include <iostream>

int main() {
    using namespace std;
    int num1, num2, num3;
    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;
    if (num1 > num2 && num1 > num3) {
        cout << "max is :  " << num1 << endl;
    } else if (num2 > num1 && num2 > num3) {
        cout << "max is :  " << num2 << endl;
    } else {
        cout << "max is :  " << num3 << endl;
    }
    return 0;
}