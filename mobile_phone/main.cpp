//
// Created by tenant on 3/21/2024.
//

#include <iostream>
#include "MobilePhone.h"

int main(){
    MobilePhone phone("iPhone 13", "John Doe", "123-456-7890");

    std::cout << "Phone model: " << phone.getModel() << std::endl;
    std::cout << "User name: " << phone.getUserName() << std::endl;
    std::cout << "Phone number: " << phone.getPhoneNumber() << std::endl;
    std::cout << "Storage: " << phone.getStorageBytes() << " bytes" << std::endl;

    phone.setUserName("Jane Doe");
    phone.addStorage(1000000);
    phone.removeStorage(345051);

    std::cout << "User name: " << phone.getUserName() << std::endl;
    std::cout << "Storage: " << phone.getStorageBytes() << " bytes" << std::endl;

    return 0;
}
