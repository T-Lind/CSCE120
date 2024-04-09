
#ifndef VECTOR
#define VECTOR

#include<string>
#include<iostream>

using namespace std;

class vector {
private:
    int length;
    int capacity;
    int *buffer;

    void resize(int new_capacity);

public:
    vector(int cap);

    vector(const vector &to_be_copied) :
            length(to_be_copied.length),
            capacity(to_be_copied.capacity),
            buffer(new int[this->capacity]) {

        for (int i = 0; i < to_be_copied.length; i++) {
            this->buffer[i] = to_be_copied.buffer[i];
        }
    }


    ~vector() {
        delete[] buffer;
        buffer = nullptr;
    }


    int &at(int index) const;

    int &operator[](const int index) const;

    void append(int value);

    void append(vector v2);

    void remove();  // throw "no value to remove"
    int size() const;    // throw "returns length"
    vector operator+(const vector &rhs) const;

    vector &operator=(const vector &rhs) {  // no const at the end because lhs is changing
        this->length = rhs.length;
        this->capacity = rhs.capacity;

        // tricky bit. Has to be done because defult constructor gave it a default capacity.
        // It is a necessary step when overwriting objects.
        delete[] buffer;
        buffer = nullptr;

        this->buffer = new int[this->capacity];

        for (int i = 0; i < rhs.length; i++) {
            this->buffer[i] = rhs.buffer[i];
        }

        return *this;
    }

    friend ostream &operator<<(ostream &os, const vector &v);
};


ostream &operator<<(ostream &os, const vector &v) {
    for (int i = 0; i < v.size(); i++) {
        os << v.at(i) << " ";
    }
    return os;
}

#endif