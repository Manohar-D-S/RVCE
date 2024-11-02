#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define SIZE 8

typedef struct Queue 
{
    char *data[SIZE];
    int front, rear;
} Q;

Q msgQ;

bool isFull(){
    return (msgQ.rear == SIZE - 1);
}

bool isEmpty(){
    return (msgQ.front == -1 && msgQ.rear == -1);
}

void send(){
    if(isFull()){                             // if full
        printf("Queue Full\n");
        return;
    }

    if(isEmpty()){                           // if empty
        msgQ.front = msgQ.rear = 0;
    } else {
        msgQ.rear = (msgQ.rear + 1) % SIZE;
    }

    msgQ.data[msgQ.rear] = malloc(50 * sizeof(char));
    printf("Enter the message you want to send: ");
    fgets(msgQ.data[msgQ.rear], 49, stdin);
    msgQ.data[msgQ.rear][strcspn(msgQ.data[msgQ.rear], "\n")] = 0; // Remove trailing newline
    printf("Message sent!!\n");
}

void receive(){
    if(isEmpty()){
        printf("Queue is Empty!!!\n");
        return;
    }

    printf("\nReceived Message: %s\n", msgQ.data[msgQ.front]);
    free(msgQ.data[msgQ.front]);
    
    if(msgQ.front == msgQ.rear) {
        msgQ.front = msgQ.rear = -1; // Queue is empty
    } else {
        msgQ.front = (msgQ.front + 1) % SIZE; // Move front pointer
    }
}

void atRear(){
    if (isEmpty()) {
        printf("Queue is Empty!!!\n");
        return;
    }
    printf("\nMessage at Rear: %s\n", msgQ.data[msgQ.rear]);
}

void atFront(){
    if (isEmpty()) {
        printf("Queue is Empty!!!\n");
        return;
    }
    printf("\nMessage at Front: %s\n", msgQ.data[msgQ.front]);
}

int main() {
    msgQ.front = msgQ.rear = -1; // Initialize queue
    int choice;

    do {
        printf("\nMenu:\n");
        printf("1] Send Message\n");
        printf("2] Receive Message\n");
        printf("3] Display Message at Rear\n");
        printf("4] Display Message at Front\n");
        printf("5] Exit\n\n");
        printf("Enter your choice: ");

        // Use scanf to read input and check for valid input
        if (scanf("%d", &choice) != 1) {
            // Clear the invalid input from the buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue; // Skip to the next iteration of the loop
        }

        getchar(); // Consume newline left in input buffer after scanf
        system("cls");
        
        switch (choice) {
            case 1:
                send();
                break;
            case 2:
                receive();
                break;
            case 3:
                atRear();
                break;
            case 4:
                atFront();
                break;
            case 5:
                printf("Thank You...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 5);

    // Free remaining allocated messages before exiting
    while (!isEmpty()) {
        receive();
    }

    return 0;
}
