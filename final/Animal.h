//
// Created by tenant on 4/30/2024.
//

#ifndef CSCE120_ANIMAL_H
#define CSCE120_ANIMAL_H

#include <iostream>
#include <cstring>

using namespace std;

class Animal {
public:
    Animal(string name, int age);
    virtual void eat() = 0;
    int getAge();
    void setAge(int age);

    virtual void setHealth(int health);
    int getHealth();

    string getName() { return name; }

private:
    string name;
    int health;
protected:
    int age;
};

class Dog : public Animal {
public:
    Dog(int age);
    void eat() override;
    void run();
    void newBirthday();
    void setHealth(int health) override;
    virtual ~Dog() = default;
};


#endif //CSCE120_ANIMAL_H
