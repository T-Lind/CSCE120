#include <iostream>
#include <cstring>

//#include "Animal.h"
#include "LinkedList.h"

int main() {
//    Dog* a = new Dog(10);
//
//    a->run();
//    cout << a->getName() << ": health: " << a->getHealth();
//    a->newBirthday();
//    cout << ", age: " << a->getAge() << endl;
//
//    delete a;

    cout << "Starting..." << endl;

    int* init = new int[]{1, 4, 6, 2, 3};


    auto* ll = new LinkedList(init, 5);

    ll->print();
    ll->reverse();
    ll->print();

    // Test out cycle detection
//    ll->head->next->next->next->next->next = ll->head->next->next;
    cout << "Cycle detected: " << ll->detectCycle() << endl;

   delete[] init;
   delete ll;
}
