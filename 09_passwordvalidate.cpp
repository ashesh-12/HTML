#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isValidPassword(char password[]) {
    int length = strlen(password);
    bool hasUpperCase = false;
    bool hasLowerCase = false;
    bool hasDigit = false;
    bool hasSpecialChar = false;

    // Check length
    if (length < 8) {
        return false;
    }

    // Check each character
    for (int i = 0; i < length; i++) {
        char c = password[i];
        if (isupper(c)) {
            hasUpperCase = true;
        } else if (islower(c)) {
            hasLowerCase = true;
        } else if (isdigit(c)) {
            hasDigit = true;
        } else if (ispunct(c)) {
            hasSpecialChar = true;
        }
    }

    // Check if all requirements are met
    return hasUpperCase && hasLowerCase && hasDigit && hasSpecialChar;
}

int main() {
    char password[100];

    printf("Enter a password: ");
    scanf("%s", password);

    if (isValidPassword(password)) {
        printf("Valid password.\n");
    } else {
        printf("Invalid password.\n");
    }

    return 0;
}

