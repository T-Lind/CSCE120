#include <iostream>
#include <string>
#include <vector>

void changeX(int *x){
    *x -= 1670;
}

int main() {
    using namespace std;

    cout << "Hello world!" << endl;

    int x = 3;
    int y = 4;
    int z = x / y; // z = 0

    string testString = "Hello";


    testString.append(" This World!");
    testString.push_back('!');
    testString.insert(11, "Amazing ");
    testString += " Sup there. " + to_string(z);

    cout << testString << endl;

    vector<double> myVec = {1.0, 2.0, 3.0, 4.0, 5.0};

    for (double i : myVec) {
        cout << i << " ";
    }

    int* xPtr = &x;
    changeX(xPtr);
    cout << *xPtr << endl;

    return 0;
}