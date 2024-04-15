#ifndef MYSTRING_H
#define MYSTRING_H

#include <iostream>
#include <stdexcept>

class MyString {
private:
    char *str;
    size_t len;
    size_t capac;

public:
    MyString();
    MyString(const char *input);
    MyString(const MyString &other);

    ~MyString();

    void resize(size_t n);

    size_t size() const;

    size_t length() const;

    const char *data() const;

    bool empty() const;

    const char &front() const;

    const char &at(size_t pos) const;

    void clear();

    size_t capacity() const;


    MyString &operator=(const MyString &other);

    MyString &operator+=(const MyString &other);

    MyString operator+(const MyString &other);

    bool operator==(const MyString &other);

    int find(const MyString &other, size_t pos = 0) const;

    friend std::ostream &operator<<(std::ostream &os, const MyString &str);

    size_t calculateLength(const char *input);

    void copyString(char *destination, const char *source);

    void concatenateString(char *destination, const char *source);

    const char *findSubstring(const char *haystack, const char *needle) const;
};

#endif // MYSTRING_H