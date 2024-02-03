#include <iostream>
#include "cstring.h"

unsigned int length(char str[]) {
    // returns the length of the string including zero (0)
    unsigned int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    return length;
}

unsigned int find(char str[], char character) {
    // returns
    //  - the index of the first occurence of character in str
    //  - the size if the character is not found
    unsigned int index = 0;
    while (str[index] != '\0') {
        if (str[index] == character) {
            return index;
        }
        index++;
    }
    return index;
}

bool equalStr(char str1[], char str2[]) {
    // returns true if str1 and str2 are equal
    // returns false otherwise
    unsigned int index = 0;
    while (str1[index] != '\0' && str2[index] != '\0') {
        if (str1[index] != str2[index]) {
            return false;
        }
        index++;
    }
    return str1[index] == str2[index];
}