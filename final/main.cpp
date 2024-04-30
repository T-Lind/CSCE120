#include <iostream>
#include <cstring>

#include "Animal.h"

int main() {
    Dog* a = new Dog(10);

    a->run();
    cout << a->getName() << ": health: " << a->getHealth();
    a->newBirthday();
    cout << ", age: " << a->getAge() << endl;

    delete a;
}
