#include <iostream>

using namespace std;

void delta(int *x) {
    x[2] = 5;
    x = &(x[2]);
}

void epsilon(char *x) {
    for (int i = 0; x[i] != '\0'; i++) {
        x[i] = x[i + 1];
    }
    x = x + 1;
}

void epsilon2(char **x) {
    for (int i = 0; (*x)[i] != '\0'; i++) {
        (*x)[i] = (*x)[i + 1];
    }
    *x = *x + 1;
}


void ex() {
    char *x = new char[3]{'a', 'b', 'c'};
    char y[3]{'d', 'e', 'f'};
    char *z = y;
    z[1] = 'g';
    cout << y[1];
    z = x;
    delete[] z;
    x = nullptr;
    z = nullptr;
    // x, z is a pointer variable, stored on stack.
    // x[1] is on the heap because x was allocated dynamically.
    // z[1] initially points to y, so z[1] would be on the stack.
    // However, when z = x, z points to same location as x, so
    // z[1] would then be on the heap.
}

void ex2() {
    long **x = new long *[7];
    for (int i = 0; i < 7; i++) {
        x[i] = new long(i * i);
    }
    cout << x[2][0];
    for (int i = 0; i < 7; i++) {
        delete x[i];
    }
}

void ex3(){
    int** x = new int*;
    *x = new int(7);
    int**y = x;
    **y = 5;
    cout << **x;
    delete *x; // memory leak, need to delete x as well
}

int main() {
//    int arr[] = {2, 4, 6, 8, 10};
//    delta(arr);
//    cout << arr[1] << arr[2];
//    cout << endl;
//    char *str = new char[10]{"Howdy!"};
//    epsilon(str);
//    cout << str << endl;  // owdy!
//    char *str2 = new char[10]{"Howdy!"};
//    epsilon2(&str2); // Pass pointer to pointer such
//    // that we can modify the pointer start
//    cout << str2 << endl; // wdy!
//    ex2();
    ex3();
}
