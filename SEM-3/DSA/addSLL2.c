// Program to add long integers using Circular Singly Linked List (CSLL)

/*
This program adds two large integers represented as strings using a single Circular Singly Linked List (CSLL).

Steps:
1. Input two numbers as strings and validate them.
2. Traverse each string from the end to handle addition from the least significant digit.
3. Add each pair of digits with carry and store the result directly into a SUM CSLL.
4. If there's remaining carry after processing, insert it as an extra node.
5. Display the final sum by traversing the SUM list in order.

Note: We use only one CSLL (SUM) here, eliminating the need to store the numbers in separate lists.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node {
    short digit;
    struct node* next;
};
typedef struct node* Node;

// Function to create a circular linked list with a dummy tail node
Node createList() {
    Node list = (Node) malloc(sizeof(struct node));
    list->digit = -1;   // Dummy value for tail node
    list->next = list;  // Circular reference
    return list;
}

// Function to free all nodes in the circular linked list
void frees(Node list) {
    if (list == NULL) return;
    Node del = list->next;
    while (del != list) {         // Traverse and free all nodes except tail
        Node temp = del;
        del = del->next;
        free(temp);
    }
    free(list); // Free the tail node
}

// Function to insert a new node with 'num' at the start of the circular list
Node insertStart(Node list, short num) {
    Node newNode = (Node) malloc(sizeof(struct node));
    newNode->digit = num;
    newNode->next = list->next;
    list->next = newNode;
    return list;
}

int main(int argc, char const *argv[]) {
    system("cls");
    char num1[40], num2[40];
    printf("Program to add Long Integers using Linked Lists\n\n");
    printf("ENTER THE FIRST NUMBER: ");
    scanf("%s", num1);
    printf("ENTER THE SECOND NUMBER: ");
    scanf("%s", num2);

    size_t len1 = strlen(num1), len2 = strlen(num2);
    Node SUM = createList();
    short carry = 0, sum = 0;

    // Traverse both numbers from the last digit to the first
    for (int i = len1 - 1, j = len2 - 1; i >= 0 || j >= 0 || carry != 0; i--, j--) {
        int digit1 = (i >= 0) ? num1[i] - '0' : 0;  // Get digit from num1 or 0 if out of bounds
        int digit2 = (j >= 0) ? num2[j] - '0' : 0;  // Get digit from num2 or 0 if out of bounds

        sum = digit1 + digit2 + carry; // Sum the digits and carry
        carry = sum / 10; // Calculate new carry
        sum = sum % 10;   // Calculate the current digit to store

        SUM = insertStart(SUM, sum); // Insert the sum digit directly to SUM list
    }

    // Display the final sum
    Node current = SUM->next;
    printf("\nThe SUM is ");
    do {
        printf("%d", current->digit);
        current = current->next;
    } while (current != SUM);
    printf("\n\n");

    // Free all allocated memory
    frees(SUM);

    return 0;
}
