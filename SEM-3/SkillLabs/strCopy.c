#include <stdio.h>

/* Function to copy a string from source to destination */
void strcopy(char *source, char *dest) {
    while (*source != '\0') {
        *dest = *source; // Copy character from source to dest
        source++;
        dest++;
    }
    *dest = '\0'; // Properly terminate the destination string
}

int main() {
    char name[25], copied[25];
    printf("Enter a string: ");
    scanf("%[^\n]", name); // Read a line of text

    strcopy(name, copied); // Copy name to copied

    printf("\nOriginal: %s\nCopied: %s\n", name, copied); // Print both strings
    return 0;
}
