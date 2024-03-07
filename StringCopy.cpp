#include <iostream>
#include <string>

using namespace std;

string *fn(string &str) {
    string *newStr = new string(str);
    return newStr;
}

int main() {
    string str = "Bruh.";
    string *newStr = fn(str);
    cout << *newStr << endl;
    delete newStr;
    return 0;
}