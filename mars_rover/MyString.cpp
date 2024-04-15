#include "MyString.h"

size_t MyString::calculateLength(const char *input) {
    size_t length = 0;
    while (input[length] != '\0') {
        ++length;
    }
    return length;
}

void MyString::copyString(char *destination, const char *source) {
    size_t i = 0;
    while (source[i] != '\0') {
        destination[i] = source[i];
        ++i;
    }
    destination[i] = '\0';
}

void MyString::concatenateString(char *destination, const char *source) {
    size_t destLen = calculateLength(destination);
    size_t i = 0;
    while (source[i] != '\0') {
        destination[destLen + i] = source[i];
        ++i;
    }
    destination[destLen + i] = '\0';
}

const char *MyString::findSubstring(const char *haystack, const char *needle) const {
    if (*needle == '\0') {
        return haystack;
    }
    for (const char *h = haystack; *h != '\0'; ++h) {
        const char *hSub = h;
        const char *nSub = needle;
        while (*hSub != '\0' && *nSub != '\0' && *hSub == *nSub) {
            ++hSub;
            ++nSub;
        }
        if (*nSub == '\0') {
            return h;
        }
    }
    return nullptr;
}

MyString::MyString() : str(new char[1]{'\0'}), len(0), capac(1) {}

MyString::MyString(const char *input) : str(new char[calculateLength(input) + 1]), len(calculateLength(input)),
                                        capac(len + 1) {
    copyString(str, input);
}

MyString::MyString(const MyString &other) : str(new char[other.capac]), len(other.len), capac(other.capac) {
    copyString(str, other.str);
}

MyString::~MyString() {
    delete[] str;
}

void MyString::resize(size_t n) {
    if (n < len) {
        str[n] = '\0';
    } else if (n > capac) {
        char *newStr = new char[n + 1];
        copyString(newStr, str);
        delete[] str;
        str = newStr;
        capac = n + 1;
    }
    len = n;
}

size_t MyString::size() const {
    return len;
}

size_t MyString::length() const {
    return len;
}

const char *MyString::data() const {
    return str;
}

bool MyString::empty() const {
    return len == 0;
}

const char &MyString::front() const {
    return str[0];
}

const char &MyString::at(size_t pos) const {
    if (pos >= len) {
        throw std::out_of_range("Index out of range");
    }
    return str[pos];
}

void MyString::clear() {
    delete[] str;
    str = new char[1]{'\0'};
    len = 0;
    capac = 1;
}

MyString &MyString::operator=(const MyString &other) {
    if (this != &other) {
        delete[] str;
        len = other.len;
        capac = other.capac;
        str = new char[capac];
        copyString(str, other.str);
    }
    return *this;
}

MyString &MyString::operator+=(const MyString &other) {
    size_t newLen = len + other.len;
    if (newLen >= capac) {
        char *newStr = new char[newLen + 1];
        copyString(newStr, str);
        concatenateString(newStr, other.str);
        delete[] str;
        str = newStr;
        capac = newLen + 1;
    } else {
        concatenateString(str, other.str);
    }
    len = newLen;
    return *this;
}

int MyString::find(const MyString &other, size_t pos) const {
    const char *found = findSubstring(str + pos, other.str);
    if (found) {
        return found - str;
    }
    return -1;
}

std::ostream &operator<<(std::ostream &os, const MyString &str) {
    os << str.str;
    return os;
}

size_t MyString::capacity() const {
    return capac;
}

MyString MyString::operator+(const MyString &other) {
    MyString result(*this);
    result += other;
    return result;
}

bool MyString::operator==(const MyString &other) {
    if (len != other.len) {
        return false;
    }
    for (size_t i = 0; i < len; ++i) {
        if (str[i] != other.str[i]) {
            return false;
        }
    }
    return true;
}
