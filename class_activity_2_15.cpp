#include <iostream>
#include <string>

int main() {
    // Initialize a string
    std::string x = "Hello";

    // Accessing characters using at() and []
    std::cout << "First character using at(): " << x.at(0) << std::endl;
    std::cout << "First character using []: " << x[0] << std::endl;

    // Append a new string
    x.append(" World");
    std::cout << "After append(): " << x << std::endl;

    // Concatenation using the + operator
    std::string y = " from C++";
    std::string result = x + y;
    std::cout << "Concatenation using + operator: " << result << std::endl;

    // Push back a character
    result.push_back('!');
    std::cout << "After push_back(): " << result << std::endl;

    // Insert a new string at a specific location
    result.insert(6, "Awesome ");
    std::cout << "After insert(): " << result << std::endl;

    // Replace characters at a specific location
    result.replace(7, 3, "Incredible");
    std::cout << "After replace(): " << result << std::endl;

    return 0;
}
