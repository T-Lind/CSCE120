#include <iostream>
#include <string>
#include <stdexcept>
void changeX(int *x) {
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


    int *xPtr = &x;
    changeX(xPtr);
    cout << *xPtr << endl;

    // error exceptions

    try {
        throw 3;
    }
//    catch (exception &exception) {
//        cout << "excp " << exception.what() << endl;
//    }
    catch(...) {
        cout << "unknown" << endl;
    }

    return 0;
}