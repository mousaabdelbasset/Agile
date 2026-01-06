#include <iostream>
#include <string>
#include <limits> // For numeric_limits
#include "User.h"
#include "Validator.h"
#include "file.h"

using namespace std;

// Helper function to get valid input
string getValidInput(string prompt, bool (*validator)(const string&, string&)) {
    string input, error;
    while (true) {
        cout << prompt;
        // Use getline for all string inputs to handle spaces safely
        getline(cin, input);

        if (validator(input, error)) {
            return input;
        }
        cout << "❌ Error: " << error << "\nTry again.\n\n";
    }
}

// Special overload for Date since it returns an array
string getValidDate(string prompt, int birthDate[3]) {
    string input, error;
    while (true) {
        cout << prompt;
        getline(cin, input);

        if (Validator::validateDateFormat(input, birthDate, error)) {
            return input;
        }
        cout << "❌ Error: " << error << "\nTry again.\n\n";
    }
}

int main() {
    cout << "=== User Registration System ===\n\n";

    string name, email, countryCode, phone, password, dateStr;
    int birthDate[3];

    // Using helper functions to keep main clean and handle retries
    name = getValidInput("Enter Name: ", Validator::validateName);
    email = getValidInput("Enter Email: ", Validator::validateEmail);
    countryCode = getValidInput("Enter Country Code (e.g., +20): ", Validator::validateCountryCode);
    phone = getValidInput("Enter Phone: ", Validator::validatePhoneNumber);
    dateStr = getValidDate("Enter Birth Date (DD-MM-YYYY): ", birthDate);
    password = getValidInput("Enter Password: ", Validator::validatePassword);

    User user(name, email, countryCode, phone, birthDate, password);

    if (FileManager::saveUser(user)) {
        cout << "\n✅ Registered & Saved Successfully!\n";
    }
    else {
        cout << "\n❌ Registration Failed due to system error.\n";
    }

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}