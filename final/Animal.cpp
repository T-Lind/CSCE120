//
// Created by tenant on 4/30/2024.
//

#include "Animal.h"

Animal::Animal(string name, int age) {
    this->name = name;
    this->age = age;
    health = 100;
}

int Animal::getAge() { return age; }
void Animal::setAge(int age) { this->age = age; }
void Animal::setHealth(int health) { this->health = health; }
int Animal::getHealth() { return health; }

Dog::Dog(int age) : Animal("Dog", age) {}
void Dog::eat() { setHealth(getHealth() + 5); }
void Dog::run() { setHealth(getHealth() - 5); }
void Dog::newBirthday() { age += 1; }