#pragma once
#include <string>
#include <vector>

class User {
public:
    std::string name;
    std::string email;
    std::string countryCode;
    std::string phoneNumber;
    int birthDate[3]; // day, month, year
    std::string password;

    User(
        const std::string& name,
        const std::string& email,
        const std::string& countryCode,
        const std::string& phoneNumber,
        int birthDate[3],
        const std::string& password
    ) {
        this->name = name;
        this->email = email;
        this->countryCode = countryCode;
        this->phoneNumber = phoneNumber;
        this->password = password;

        for (int i = 0; i < 3; i++)
            this->birthDate[i] = birthDate[i];
    }
};