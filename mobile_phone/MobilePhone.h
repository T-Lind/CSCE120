//
// Created by tenant on 3/21/2024.
//
#include <string>

#ifndef CSCE120_MOBILEPHONE_H
#define CSCE120_MOBILEPHONE_H

class MobilePhone {
public:
    MobilePhone(std::string model, std::string userName, std::string phoneNumber);

    ~MobilePhone();

    std::string getModel() const;

    std::string getUserName() const;

    std::string getPhoneNumber() const;

    void setUserName(std::string userName);

    void addStorage(int storageAmountBytes);

    void removeStorage(int storageAmountBytes);

    int getStorageBytes() const;

private:
    std::string model;
    std::string userName;
    std::string phoneNumber;
    int storageBytes;

};


#endif //CSCE120_MOBILEPHONE_H
