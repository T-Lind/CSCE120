//
// Created by tenant on 3/21/2024.
//

#include "MobilePhone.h"


MobilePhone::MobilePhone() { // default constructor
    this->model = "Unknown";
    this->userName = "Unknown";
    this->phoneNumber = "Unknown";
    this->storageBytes = 1000000;   // Let's say this is the initial data on the phone (OS or something)
}

MobilePhone::MobilePhone(std::string model, std::string userName, std::string phoneNumber) {
    this->model = model;
    this->userName = userName;
    this->phoneNumber = phoneNumber;
    this->storageBytes = 1000000;   // Let's say this is the initial data on the phone (OS or something)
}

MobilePhone::~MobilePhone() {
    // nothing to do here
}

std::string MobilePhone::getModel() const {
    return model;
}

std::string MobilePhone::getUserName() const {
    return userName;
}

std::string MobilePhone::getPhoneNumber() const {
    return phoneNumber;
}

void MobilePhone::setUserName(std::string userName) {
    this->userName = userName;
}

void MobilePhone::addStorage(int storageAmountBytes) {
    this->storageBytes += storageAmountBytes;
}

void MobilePhone::removeStorage(int storageAmountBytes) {
    this->storageBytes -= storageAmountBytes;
}

int MobilePhone::getStorageBytes() const {
    return storageBytes;
}

