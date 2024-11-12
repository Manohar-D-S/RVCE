#include <stdio.h>
#include <stdlib.h>
#define MAX 6

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef Node* NODE;

NODE enqueue(NODE list, int* count) {
    if (*count == MAX - 1) {
        printf("Queue is Full\n\n");
        return list;
    }
    
    int data;
    printf("Enter the data to enqueue : ");
    scanf("%d", &data);

    NODE newNode = (NODE) malloc(sizeof(Node));
    newNode->data = data;
    
    if (*count == -1) {
        list = newNode;
        newNode->next = newNode;  // Self-loop to form circular link
    } else {
        newNode->next = list->next;
        list->next = newNode;
    }
    
    (*count)++;
    return newNode;
}

NODE dequeue(NODE list, int *count, int silent) {
    if (*count == -1) {
        if (!silent) {
            printf("Queue is empty\n");
        }
        return NULL;
    } else if (list->next == list) {
        if (!silent) {
            printf("%d dequeued\n", list->data);
        }
        free(list);
        (*count)--;
        return NULL;
    }

    NODE del = list->next;
    while (del->next != list)
        del = del->next;
    
    del = list->next;
    list->next = del->next;
    
    if (!silent) {
        printf("%d dequeued\n", del->data);
    }
    
    free(del);
    (*count)--;
    return list;
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
    } while (temp != list->next);
    printf("\n");
}

int main() {
    NODE cll = NULL;
    int opt = 0;
    int count = -1;
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
                cll = dequeue(cll, &count, 0);
                break;
            case 3:
                display(cll, count);
                break;
            case 4:
                while (cll != NULL) {
                    cll = dequeue(cll, &count, 1);  // Pass 1 to suppress the dequeue message
                }
                printf("Bye..Bye...\n\n");
                exit(0);
                break;
            default:
                printf("Invalid option!! Try again\n\n");
        }
    }
}
