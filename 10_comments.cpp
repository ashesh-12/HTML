#include <stdio.h>
#include <stdbool.h>

// Define states of the DFA
enum State {
    
    q1,   // Transition state after seeing '/'
    qf1,  // Final state for single-line comment
    qf2,  // Final state for multi-line comment
    q0,   // Invalid state
    q2,   // Transition state after seeing '/*'
    q3, 
    trap,  // Transition state after seeing '/*' and '*'
};

// Function to validate C comments using DFA
bool isValidCComment(char code[]) {
    enum State currentState = q0;
    int i = 0;

    while (code[i] != '\0') {
        switch (currentState) {
            case q0:  // Initial state
                if (code[i] == '/') {
                    currentState = q1;
                }
                break;
            case q1:  // Transition state after seeing '/'
                if (code[i] == '/') {
                    currentState = qf1;  // Single-line comment
                } else if (code[i] == '*') {
                    currentState = q2;   // Start of multi-line comment
                } else {
                    currentState = q0;   // Reset if neither '/' nor '*'
                }
                break;
            case q2:  // Transition state after seeing '/*'
                if (code[i] == '*') {
                    currentState = q3;   // Possible end of multi-line comment
                }
                break;
            case q3:  // Transition state after seeing '/*' and '*'
                if (code[i] == '/') {
                    currentState = qf2;  // End of multi-line comment
                } else if (code[i] != '*') {
                    currentState = q2;   // Resume multi-line comment search
                } else {
                    currentState = q3;   // Continue checking for end of multi-line comment
                }
                break;
            case qf2: //Checks after reacing reaching end of multiple comments
                if (code[i] == '/') {
                    currentState = q1;  
                
                }
                else if(code[i] == ' ')
                    currentState = qf2;
                else {
                    currentState = trap;   
                }
                break;
        }
        i++;
    }

    // Check if the last state is a valid final state for a C comment
    return currentState == qf1 || currentState == qf2;
}

int main() {
    char code[1000];

    printf("Enter C code: ");
    scanf("%[^\n]", code); // Read the input string

    if (isValidCComment(code)) {
        printf("Valid C comment.\n");
    } else {
        printf("Invalid C comment.\n");
    }

    return 0;
}
