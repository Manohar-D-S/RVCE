//Program to add long integers using Circular Singly Linked List

/*
ok so during our class today I was able to  figured out few methods to add 2 ints using LLs.
This is one of it, basically the simplest noobie method.
1. Take 2 numbers as strings(check if they are valid numbers)
2. Based on the len of 2 strings(basically no of digits) creating a CSLL for both.
3. Then traverse thru both the lists until they reach their respective last node(tail node) add their respective digits and insert the sum as node to the SUM LL.
4. if there's a carry left out then add it another node to the SUM LL.
5. then display the sum thats it.

NOTE:Tail Node wont be considered for addition; its just to mark the lastnode, its possible to implement without using this tail node
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
    char num1[20], num2[20];
    printf("Program to add Long Integers using Linked Lists\n\n");
    printf("ENTER THE FIRST NUMBER: ");
    scanf("%s", num1);
    printf("ENTER THE SECOND NUMBER: ");
    scanf("%s", num2);

    size_t len1 = strlen(num1), len2 = strlen(num2);
    Node A = createList(), B = createList();

    // Populate linked lists A and B with digits of num1 and num2 in reverse order
    for (int i = 0, j = 0; i < len1 || j < len2; i++, j++) {
        if (i < len1) {
            A = insertStart(A, num1[i] - '0');
        }
        if (j < len2) {
            B = insertStart(B, num2[j] - '0');
        }
    }

    // Sum linked lists A and B to produce the SUM list
    Node SUM = createList(), a = A->next, b = B->next;
    short carry = 0, sum = 0;

    // Traverse both lists and add corresponding digits
    while ((a != A) || (b != B) || carry != 0) {
        if (a == A) {  // When list A is exhausted
            sum = (carry + b->digit) % 10;
            carry = (carry + b->digit) / 10;
            b = b->next;
        } else if (b == B) {  // When list B is exhausted
            sum = (carry + a->digit) % 10;
            carry = (carry + a->digit) / 10;
            a = a->next;
        } else {  // Both lists have digits left
            sum = (carry + a->digit + b->digit) % 10;
            carry = (carry + a->digit + b->digit) / 10;
            a = a->next;
            b = b->next;
        }
        SUM = insertStart(SUM, sum);  // Insert sum digit at the start of SUM list
    }

    if (carry != 0) {  // Add any remaining carry as a new node
        SUM = insertStart(SUM, carry);
    }

    // Display the final sum
    a = SUM->next;
    printf("\nThe SUM is ");
    do {
        printf("%d", a->digit);
        a = a->next;
    } while (a != SUM);
    printf("\n\n");

    // Free all allocated memory
    frees(A);
    frees(B);
    frees(SUM);

    return 0;
}


/*And the other methods are,
1. using a CDLL
2. Initializing two LL for storing numbers and the using one of those two for storing the sum also
3. scanning 2 i/p strings and while traversing each of them creating one CSLL that stores the sums directly(no lists for storing numbers)

Well 1 & 3 are more efficient or even combining those 2 methods tooo

*/