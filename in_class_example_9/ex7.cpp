#include <iostream>
#include "car_class.h"

using namespace std;

int *createArray(const int capacity) {
    int *buffer = new int[capacity];
    return buffer;
}

void resize(int *&buffer, const int old_capacity, const int new_capacity) {
    cout << "resize called" << endl;
    int *temp = buffer;
    buffer = new int[new_capacity];

    // One assumption here. What is it?

    for (int i = 0; i < old_capacity; i++) {
        buffer[i] = temp[i];
    }

    delete[] temp;
}

void append(int *&buffer, int &length, int &size, const int &value) {
    if (length < size) {
        buffer[length] = value;
        length = length + 1;
    } else {
        int new_size = 2 * size;
        resize(buffer, size, new_size);
        size = new_size;
        buffer[length] = value;
        length = length + 1;
    }
}

void printArray(int *&buffer, const int &length) {
    for (int i = 0; i < length; i++) {
        cout << buffer[i] << ", ";
    }
    cout << endl;
}

int main() {
    int size = 2;
    int *v = createArray(size);
    int length = 0;

    append(v, length, size, 1);
    printArray(v, length);

    append(v, length, size, 2);
    printArray(v, length);

    append(v, length, size, 3);
    printArray(v, length);

    append(v, length, size, 4);
    printArray(v, length);

    delete[] v;
}