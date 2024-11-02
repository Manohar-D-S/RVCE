/*
This is the main file of the queue implementation
--> [circularArrayQueue.h, arrayQueue.h, ] if anyone of these files #included this program wont work. So take care
*/

#include <stdio.h>
#include <stdbool.h>
#include "arrayQueue.h"             // Ensure these headers exist and are correctly implemented
#include "circularArrayQueue.h"      // Ensure these headers exist and are correctly implemented

void displayCircularMenu() {
    printf("Circular Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

void displayLinearMenu() {
    printf("Linear Queue Operations:\n");
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display Queue\n");
    printf("4. Check if Queue is Empty\n");
    printf("5. Check Size of Queue\n");
    printf("6. Front Element\n");
    printf("7. End Element\n");
    printf("0. Exit\n");
    printf("Enter your choice: ");
}

int main() {
    int choice, data, queueType;
    QUEUE qCircular;          // Circular Queue instance
    QUEUE qLinear;            // Linear Queue instance
    
    // Initialize the queues
    qCircular.head = qCircular.tail = -1;
    qLinear.head = qLinear.tail = -1;

    // Ask the user which type of queue to use
    printf("Choose Queue Type:\n");
    printf("1. Circular Queue\n");
    printf("2. Linear Queue\n");
    printf("Enter your choice: ");
    scanf("%d", &queueType);

    if (queueType == 1) {
        // Circular Queue operations
        do {
            displayCircularMenu();
            scanf("%d", &choice);
            
            switch (choice) {
                case 1:
                    printf("Enter data to enqueue in Circular Queue: ");
                    scanf("%d", &data);
                    enQ(data);  // Call circular queue enqueue
                    break;

                case 2:
                    deQ();  // Call circular queue dequeue
                    break;

                case 3:
                    printf("Circular Queue contents: ");
                    printQueue();  // Call circular queue print
                    break;

                case 0:
                    printf("Exiting...\n");
                    break;

                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 0);

    } else if (queueType == 2) {
        // Linear Queue operations
        do {
            displayLinearMenu();
            scanf("%d", &choice);
            
            switch (choice) {
                case 1:
                    printf("Enter data to enqueue in Linear Queue: ");
                    scanf("%d", &data);
                    enqueue(&qLinear, data);  // Call linear queue enqueue
                    break;

                case 2:
                    dequeue(&qLinear);  // Call linear queue dequeue
                    break;

                case 3:
                    printf("Linear Queue contents: ");
                    printQueue(&qLinear);  // Call linear queue print
                    break;

                case 4:
                    if (isEmpty(&qLinear))
                        printf("Linear Queue is empty.\n");
                    else
                        printf("Linear Queue is not empty.\n");
                    break;

                case 5:
                    printf("Size of Linear Queue: %d\n", size(&qLinear));
                    break;

                case 6:
                    if (!isEmpty(&qLinear))
                        printf("Front element in Linear Queue: %d\n", queueFront(&qLinear));
                    else
                        printf("Queue is empty.\n");
                    break;

                case 7:
                    if (!isEmpty(&qLinear))
                        printf("End element in Linear Queue: %d\n", queueEnd(&qLinear));
                    else
                        printf("Queue is empty.\n");
                    break;

                case 0:
                    printf("Exiting...\n");
                    break;

                default:
                    printf("Invalid choice. Please try again.\n");
            }
        } while (choice != 0);

    } else {
        printf("Invalid choice for queue type. Exiting program.\n");
    }

    return 0;
}
