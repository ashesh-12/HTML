#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isValidCharacter(char ch) {
    return (isalnum(ch) || ch=='.'|| ch == '_' || ch == '-' || ch == '@');
}

bool isValidEmail(char email[]) {
    int length = strlen(email);
    int atIndex = -1;
    int dotIndex = -1;

    // Finding position of '@' and '.'
    for (int i = 0; i < length; i++) {
        if (email[i] == '@') {
            if (atIndex != -1) { // More than one '@' symbol
                printf("More than one '@' symbol\n");
                return false;
            }
            atIndex = i;
        } else if (email[i] == '.') {
            dotIndex = i;
        }
    }

    // Checking if '@' and '.' exist and in the right positions
    if (atIndex == -1 || dotIndex == -1 || atIndex > dotIndex || atIndex == 0 || dotIndex == length - 1) {
        printf("Invalid positions of '@' and '.'\n");
        return false;
    }

    // Iterate through each character in the email address
    for (int i = 0; i < length; i++) {
        char c = email[i];

        // Check if the character is valid
        if (!isValidCharacter(c)) {
            printf("Invalid character: %c\n", c);
            return false;
        }
    }

    return true;
}

int main() {
    char email[100];

    printf("Enter an email address: ");
    scanf("%s", email);

    if (isValidEmail(email)) {
        printf("Valid email address.\n");
    } else {
        printf("Invalid email address.\n");
    }

    return 0;
}

