#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Define states
enum State {
    Q0, Q1, ACCEPT
};

// Function to check if a string is accepted by the NFA
bool isValidString(const char *str, enum State currentState, int index) {
    // Define transitions for each state
    switch (currentState) {
        case Q0:
            if (str[index] == '\0') {
                // End of string, check if in ACCEPT state
            return currentState == ACCEPT;
            } else if (str[index] == '0') {
                // Transition to Q1
                return isValidString(str, Q1, index + 1);
            }
            break;

        case Q1:
            if (str[index] == '\0') {
                // End of string, check if in ACCEPT state
                return currentState == ACCEPT;
            } else if (str[index] == '1') {
                // Transition to ACCEPT
                return isValidString(str, ACCEPT, index + 1);
            }
            break;

        case ACCEPT:
            // Stay in ACCEPT state
            return true;

        default:
            return false;
    }
    return false;
}

int main() {
    char inputstring[100];
    printf("Enter a string: ");
    scanf("%s", inputstring);
    if (isValidString(inputstring, Q0, 0)) {
        printf("String is accepted\n");
    } else {
        printf("String is not accepted\n");
    }
    return 0;
}
