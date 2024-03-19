#include<iostream>
#include "car_class.h"

Car::Car(){
    seats = 4;
    power = 100;
    char d[] = "Red";
    init_color(d);
}
    
Car::Car(char* c, int hp, int s){
    seats = s;
    set_power_in_hp(hp);
    init_color(c);
}

void Car::init_color(char * newcolor){
    int i = 0;
    while (newcolor[i] != 0){
        color[i] = newcolor[i];
        i++;
    }
    color[i] = 0;
}

void Car::print_car(){
    std::cout << "Color : " << color << std::endl; 
    std::cout << "Power : " << get_power_in_hp() << std::endl; 
    std::cout << "Seats : " << seats << std::endl;
    std::cout << std::endl; 
}

void Car::set_power_in_hp(int hp) {
    power = 0.74569987 * hp;
}

int Car::get_power_in_hp() const {
    return (int)(power / 0.74569987);
}