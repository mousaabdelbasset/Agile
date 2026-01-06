#pragma once
#include <fstream>
#include <string>
#include <iostream>
#include <functional> // For std::hash

class FileManager {
private:
    // Simple hashing simulation (In production use libraries like bcrypt)
    static size_t hashPassword(const std::string& password) {
        std::hash<std::string> hasher;
        return hasher(password);
    }

public:
    static bool saveUser(const User& user) {
        // Appending to a single database file
        std::ofstream file("users_db.txt", std::ios::app);

        if (!file.is_open()) {
            std::cerr << "Error: Could not open database file for writing.\n";
            return false;
        }

        // Hashing the password before saving
        size_t hashedPassword = hashPassword(user.password);

        // Saving in a structured format (CSV-like or just readable blocks)
        file << "--------------------------------\n";
        file << "Name: " << user.name << "\n";
        file << "Email: " << user.email << "\n";
        file << "Phone: " << user.countryCode << user.phoneNumber << "\n";
        file << "Birth Date: "
            << user.birthDate[0] << "-"
            << user.birthDate[1] << "-"
            << user.birthDate[2] << "\n";
        file << "Password Hash: " << hashedPassword << "\n"; // Save hash, NOT plain text
        file << "--------------------------------\n";

        file.close();
        return true;
    }
};