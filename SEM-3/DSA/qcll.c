#include <stdio.h>
#include <stdlib.h>
#define MAX 6  // Maximum queue size

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* NODE;

NODE enqueue(NODE list, int* count) {
    if (*count == MAX - 1) {  // Check if queue is full
        printf("Queue is Full\n\n");
        return list;
    }
    
    int data;
    printf("Enter the data to enqueue : ");
    scanf("%d", &data);

    NODE newNode = (NODE) malloc(sizeof(Node));
    newNode->data = data;
    
    if (*count == -1) {  // Initialize first element in the circular queue
        list = newNode;
        newNode->next = newNode;  // Self-loop for single element
    } else {
        newNode->next = list->next;  // Insert new node at the start
        list->next = newNode;
    }
    
    (*count)++;
    return newNode;  // Return updated tail of the list
}

NODE dequeue(NODE list, int *count, int silent) {
    if (*count == -1) {  // Check if queue is empty
        if (!silent) printf("List is empty\n");
        return NULL;
    } else if (list->next == list) {  // Handle dequeuing the last element
        if (!silent) printf("%d dequeued\n", list->data);
        free(list);
        (*count)--;
        return NULL;
    }

    // Standard dequeue: remove node at start of the circular queue
    NODE del = list->next;
    list->next = del->next;
    if (!silent) printf("%d dequeued\n", del->data);
    free(del);
    (*count)--;
    return list;  // Return updated tail
}

void display(NODE list, int count) {
    if (count == -1) {
        printf("Queue is Empty\n\n");
        return;
    }

    NODE temp = list->next;
    printf("Queue: ");
    do {
        printf("%d\t", temp->data);
        temp = temp->next;
    } while (temp != list->next);  // Traverse circularly until back to start
    printf("\n");
}

int main() {
    NODE cll = NULL;  // Circular linked list (queue)
    int opt = 0;
    int count = -1;  // Track number of elements in the queue
    system("cls");
	
    while (1) {
        printf("\nChoose the function you want to perform on the Queue:\n");
        printf("1] Enqueue\n2] Dequeue\n3] Display\n4] EXIT\n\n");
        printf("Enter the option : ");
        scanf("%d", &opt);
	system("cls");
	    
        switch (opt) {
            case 1:
                cll = enqueue(cll, &count);
                break;
            case 2:
                cll = dequeue(cll, &count, 0);  // Normal dequeue with message
                break;
            case 3:
                display(cll, count);
                break;
            case 4:
                while (cll != NULL) {
                    cll = dequeue(cll, &count, 1);  // Silent dequeue during exit
                }
                printf("Bye..Bye...\n\n");
                exit(0);
                break;
            default:
                printf("Invalid option!! Try again\n\n");
        }
    }
}
