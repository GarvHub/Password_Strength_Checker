#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

struct ValidationResult {
    bool is_valid;
    vector<string> errors;
};

class PasswordValidator {
private:
    int min_length;
    bool require_special;
    bool require_number;

public:
    // Scalability: Constructor allows configuration of rules.
    // (e.g.--> if the company changes requirements to 12 chars later).
    PasswordValidator(int length = 8, bool special = true, bool number = true) 
        : min_length(length), require_special(special), require_number(number) {}

    ValidationResult validate(const string& password) {
        ValidationResult result;
        result.is_valid = true; // Assuming valid until a check fails

        // Rule 1: Length Check
        if (password.length() < min_length) {
            result.is_valid = false;
            result.errors.push_back("Length must be at least " + to_string(min_length) + " characters.");
        }

        // Rule 2 & 3: Character Content Check
        // using a single pass O(N) loop for performance
        bool has_number = false;
        bool has_special = false;

        for (char c : password) {
            if (isdigit(c)) has_number = true;
            if (ispunct(c)) has_special = true;
        }

        if (require_number && !has_number) {
            result.is_valid = false;
            result.errors.push_back("Must contain at least one number (0-9).");
        }

        if (require_special && !has_special) {
            result.is_valid = false;
            result.errors.push_back("Must contain at least one special character (!@#...).");
        }

        return result;
    }
};

int main() {
    
    PasswordValidator validator(8, true, true);

    // The input list required by the problem statement
    vector<string> passwords = {"abc", "123456", "Pass@123", "Admin"};

    cout << "=== Password Validator Report ===" << endl;

    for (const string& pwd : passwords) {
        ValidationResult res = validator.validate(pwd);

        cout << "Testing: [" << pwd << "]" << endl;
        
        if (res.is_valid) {
            cout << "  [SUCCESS] Password Accepted" << endl;
        } else {
            cout << "  [FAILED] Reasons:" << endl;
            for (const string& err : res.errors) {
                cout << "   - " << err << endl;
            }
        }
        cout << "-----------------------------------" << endl;
    }

    return 0;
}