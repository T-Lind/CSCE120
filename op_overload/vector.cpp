#include <iostream>
#include "vector.h"

using namespace std;

vector::vector(int cap = 10) : length(0), capacity(cap), buffer(new int[cap]) {
}

void vector::resize(int new_capacity) {
    int *temp = buffer;
    buffer = new int[new_capacity];

    // int *x = new int(2);
    // delete x;

    for (int i = 0; i < length; i++) {
        buffer[i] = temp[i];
    }

    capacity = new_capacity;

    delete[] temp;   // fixed to use array delete
    temp = nullptr;
}

int &vector::at(int index) const {
    if (index >= length) {
        throw runtime_error("out of bound access");
    }

    return buffer[index];  // Address is not returned
}

void vector::append(int value) {
    if ((length + 1) < capacity) {
        this->buffer[length] = value;
        this->length++;
    } else {
        resize(2 * capacity);
        buffer[length] = value;
        length++;
    }
}

void vector::append(vector v2) {
    int new_length = length + v2.size();
    if (new_length > capacity) {
        resize(new_length + 100);
    }

    for (int i = 0; i < v2.size(); i++) {
        append(v2.at(i));
    }
}

int vector::size() const {
    return length;
}

void vector::remove() {
    length--;
}

vector vector::operator+(const vector &rhs) const {
    if (this->length == rhs.length) {               // Check if the vectors have the same size
        vector result(this->length);                // Create a new vector to store the result
        for (int i = 0; i < this->length; i++) {    // Loop through the array elements
            result.append(this->at(i) + rhs.at(i)); // Add the corresponding elements and set the result element
        }
        return result; // Return the result vector
    } else {
        throw runtime_error("Vector lengths do not match");
    }
}

int &vector::operator[](const int index) const {
    return this->at(index);
}


