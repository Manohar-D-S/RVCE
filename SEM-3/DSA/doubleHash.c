#include <stdio.h>
#include <stdlib.h>
#define SIZE 10
int hashT[SIZE];



void clearScreen() {
    #ifdef _WIN32
        system("cls"); // Windows
    #elif __linux__
        system("clear"); // Linux/Unix
    #else
        printf("Clear screen is not supported on this platform.\n");
    #endif
}

int h1(int key) {
    return key % SIZE;
}

int h2(int key) {
    return 1 + (key % (SIZE - 2));
}

void display() {
    printf("| INDEX |   VALUE |\n");
    printf("+-------+---------+\n");
    for (int i = 0; i < SIZE; i++) {
        if (hashT[i] == -1)
            printf("|%7d|  EMPTY  |\n", i);
        else if (hashT[i] == -2)
            printf("|%7d| DELETED |\n", i);
        else
            printf("|%7d|%9d|\n", i, hashT[i]);
    }
    printf("+-------+---------+\n");
}

void insert() {
    int key, i = 0;
    printf("Enter the element to be hashed: ");
    scanf("%d", &key);

    while (i < SIZE) {
        int index = (h1(key) + i * h2(key)) % SIZE;
        if (hashT[index] == -1 || hashT[index] == -2) {
            hashT[index] = key;
            printf("%d has been hashed at index %d.\n", key, index);
            return;
        }
        i++;
    }

    printf("Unable to hash the element. Hash table is full.\n");
}

int search(int key) {
    int i = 0;
    while (i < SIZE) {
        int index = (h1(key) + i * h2(key)) % SIZE;
        if (hashT[index] == -1)
            return -1;
        if (hashT[index] == key)
            return index;
        i++;
    }
    return -1;
}

void deletion() {
    int key, index;
    printf("Enter the element to be deleted: ");
    scanf("%d", &key);

    index = search(key);
    if (index == -1) {
        printf("Element not found in the hash table.\n");
    } else {
        hashT[index] = -2;
        printf("Element %d removed from the hash table.\n", key);
    }
}

int main() {
    for (int i = 0; i < SIZE; i++)
        hashT[i] = -1;

    int choice;
    clearScreen();
    while (1) {

        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        clearScreen();

        switch (choice) {
            case 1: insert(); break;
            case 2: {
                int key;
                printf("Enter the key to search: ");
                scanf("%d", &key);
                int index = search(key);
                if (index == -1)
                    printf("Key not found.\n");
                else
                    printf("Key found at index %d.\n", index);
                break;
            }
            case 3: deletion(); break;
            case 4: display(); break;
            case 5: printf("Bye..Bye.."); exit(0);
            default: printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
