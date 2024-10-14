//Stack using array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 50

void push(char* stack, int *top, char data){
    if(*top == SIZE-1)
        printf("Stack Overflow.\n\n");
    else
        stack[++(*top)] = data;
}

void pop(char* stack, int *top){
    if(*top == -1)
        printf("Stack Underflow.\n\n");
    else
        printf("%c popped\n\n", stack[(*top)--]);
}

bool isEmpty(char *stack, int top){
    return (top == -1);
}

bool isFull(char *stack, int top){
    return (top == SIZE - 1);
}

void display(char* stack, int top, int flag) {
    if (flag) {
        for (int i = 0; i <= top; i++) { 
            printf("%c\t", stack[i]);
        }
    } else {
        if (top != -1) 
            printf("Top element: %c\n", stack[top]);
        else
            printf("Stack is empty.\n");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    char stack[SIZE];
    int top = -1;

    int opt = 1;

    while (opt) {
        printf("\nChoose the operation that you want to implement on the Stak:\n");
        printf("1) PUSH\n");
        printf("2) POP\n");
        printf("3) isEmpty\n");
		printf("4) isFUll\n");
        printf("5) showTop\n");
        printf("6) diplayStack\n");
        printf("7) EXIT\n\n");

        printf("Enter the option: ");
        scanf("%d", &opt);
        system("clear");

        switch (opt) {
            char letter;
            case 1:
                printf("Enter the character you want to PUSH: ");
                scanf(" %c", &letter);
                push(stack, &top, letter); 
                break;
            case 2:
                pop(stack, &top); 
                break;
            case 3:
                printf("%s\n", isEmpty(stack, top) ? "true" : "false");
                break;
			case 4:
				printf("%s\n", isFull(stack, top) ? "true" : "false");
                break;
            case 5:
				display(stack, top, 0);
                break;
            case 6:
				display(stack, top, 1);
                break;
            case 7:
                opt = 0;  // Exit the loop
                break;
            default:
                printf("Invalid Option.\n");
        }
    }

    printf("Program Ended.\nThank You\n");
    return 0;
}
