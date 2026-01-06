#pragma once
#include <string>
#include <cctype>
#include <algorithm>

class Validator {
public:

    // 1️⃣ Name (Modified to allow spaces)
    static bool validateName(const std::string& name, std::string& error) {
        if (name.empty() || name.length() > 50) {
            error = "Name must be between 1 and 50 characters.";
            return false;
        }

        // Check if starts with a letter
        if (!isalpha(name[0])) {
            error = "Name must start with a letter.";
            return false;
        }

        // Allow letters and spaces only
        for (char c : name) {
            if (!isalpha(c) && c != ' ') {
                error = "Name must contain letters and spaces only.";
                return false;
            }
        }
        return true;
    }

    // 2️⃣ Email
    static bool validateEmail(const std::string& email, std::string& error) {
        size_t atPos = email.find('@');
        size_t dotPos = email.find('.', atPos);

        if (atPos == std::string::npos || dotPos == std::string::npos) {
            error = "Email must contain '@' and '.'";
            return false;
        }

        if (atPos == 0 || dotPos <= atPos + 1 || dotPos == email.length() - 1) {
            error = "Invalid email format.";
            return false;
        }
        return true;
    }

    // 3️⃣ Phone
    static bool validateCountryCode(const std::string& code, std::string& error) {
        if (code.empty() || code[0] != '+') {
            error = "Country code must start with '+'";
            return false;
        }

        for (size_t i = 1; i < code.length(); i++) {
            if (!isdigit(code[i])) {
                error = "Country code must contain digits only after '+'";
                return false;
            }
        }
        return true;
    }

    static bool validatePhoneNumber(const std::string& phone, std::string& error) {
        if (phone.empty()) {
            error = "Phone number cannot be empty.";
            return false;
        }
        for (char c : phone) {
            if (!isdigit(c)) {
                error = "Phone number must contain digits only.";
                return false;
            }
        }
        return true;
    }

    // 4️⃣ Date of Birth
    static bool validateDateFormat(const std::string& date, int birthDate[3], std::string& error) {
        if (date.length() != 10) {
            error = "Date must be in format DD-MM-YYYY";
            return false;
        }

        if (date[2] != '-' || date[5] != '-') {
            error = "Date separator must be '-'";
            return false;
        }

        for (size_t i = 0; i < date.length(); ++i) {
            if (i == 2 || i == 5) continue;
            if (!isdigit(date[i])) {
                error = "Date must contain digits only";
                return false;
            }
        }

        int day = std::stoi(date.substr(0, 2));
        int month = std::stoi(date.substr(3, 2));
        int year = std::stoi(date.substr(6, 4));

        if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900) {
            error = "Invalid date values";
            return false;
        }

        birthDate[0] = day;
        birthDate[1] = month;
        birthDate[2] = year;

        return true;
    }

    // 5️⃣ Password
    static bool validatePassword(const std::string& password, std::string& error) {
        if (password.length() < 8 || password.length() > 20) {
            error = "Password must be between 8 and 20 characters.";
            return false;
        }

        bool hasLetter = false, hasDigit = false, hasSpecial = false;

        for (char c : password) {
            if (isalpha(c)) hasLetter = true;
            else if (isdigit(c)) hasDigit = true;
            else hasSpecial = true;
        }

        if (!hasLetter || !hasDigit || !hasSpecial) {
            error = "Password must contain letters, digits, and special characters.";
            return false;
        }
        return true;
    }
};