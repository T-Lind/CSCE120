#include <iostream>

// Write a function that swaps two numbers
void swap(int* ptr1, int* ptr2){
    int temp = *ptr1;
    *ptr1 = *ptr2;
    *ptr2 = temp;
}

int main() {
    int x = 5;
    int* p = &x;
    std::cout << "x = " << x << std::endl;
    std::cout << "p = " << p << std::endl;
    std::cout << "*p = " << *p << std::endl;

    // Now for new code
    int* a = new int(5);
    int* b = new int(3);

    std::cout << "a: " << *a << ", b: " << *b << std::endl;
    swap(a, b);

    std::cout << "a: " << *a << ", b: " << *b << std::endl;

    delete a;
    delete b;

    return 0;
}