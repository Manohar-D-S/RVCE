#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

void splitCamelCase(char* str, char type);
void combineCamelCase(char* str, char type);

int main() {
    char input[500];
    
    // Read multiple lines of input
    while(fgets(input, sizeof(input), stdin)) {
        // Remove the trailing newline character
        input[strcspn(input, "\r\n")] = '\0';
        
        // Determine operation and type (S or C, followed by M, C, or V)
        char operation = input[0];
        char type = input[2];
        char* content = input + 4;
        
        if (operation == 'S') {
            // Split operation
            splitCamelCase(content, type);
        } else if (operation == 'C') {
            // Combine operation
            combineCamelCase(content, type);
        }
        
        printf("\n");  // Ensure a newline between outputs
    }
    
    return 0;
}

void splitCamelCase(char* str, char type) {
    int firstWord = 1; // Flag to check if it's the first word
    for (int i = 0; str[i] != '\0'; i++) {
        // Check for uppercase letters (start of a new word)
        if (isupper(str[i])) {
            if (!firstWord) {
                printf(" ");  // Print space before the new word if it's not the first word
            }
            printf("%c", tolower(str[i]));  // Convert to lowercase
            firstWord = 0; // Set the flag to false after the first word is printed
        } else if (str[i] == '(') {
            // Skip method parentheses
            break;
        } else {
            if (firstWord) {
                printf("%c", str[i]);  // Print the first character without space
            } else {
                printf("%c", str[i]); // Print normally
            }
        }
    }
}

void combineCamelCase(char* str, char type) {
    int capitalizeNext = (type == 'C');  // For classes, start with uppercase
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == ' ') {
            capitalizeNext = 1;  // Capitalize the next word
        } else {
            if (capitalizeNext) {
                printf("%c", toupper(str[i]));  // Capitalize the letter
                capitalizeNext = 0;  // Reset flag
            } else {
                printf("%c", str[i]);  // Print normally
            }
        }
    }
    
    // For methods, append ()
    if (type == 'M') {
        printf("()");
    }
}
