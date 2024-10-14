#include <stdio.h>
#define MAX 10

int push(int stack[], int top) {
    int data;
    printf("Enter the element to push into the stack : ");scanf("%d", &data);
    if(top == MAX - 1) {
        printf("Stack Oveflow");
        return top;
    } else {
        stack[top++] = data;
        return top;
    }
}

int pop(int stack[], int top) {
    if(top == -1){
        printf("Stack Underflow");
    } else {
        int popped_data = stack[top];
        stack[top--] = NULL;
        return top;
    }
}

int displayStack(int stack[], int top) {
    for (;top >= 0; top--)
    {
        printf("%d", stack[top]);
    }
}

int showTop(int stack[], int  top){
    (top == -1) ? printf("Stack is empty!!!") : printf("%d", stack[top]);
}


int main(int argc, char const *argv[])
{
    int stack[10] = {NULL};
    int top = 0;
    int opt;


    printf("This is a STACK PROGRAM with default size of the stack being 10. Pick the actions that you wish to perform on the stack from below and enter the option number.");

    do {
        printf("1.  PUSH\n2.  POP\n3.  DISPLAY STACK\n4.  SHOW TOP\n5.  EXIT\n\nEnter your option : ");
        scanf("%d", &opt);
        switch (opt) {
        case 1:
            top = push(stack, top);
            break;
        case 2:
            top = pop(stack, top);
            break;

        case 3:
            displayStack(stack, top);
            break;

        case 4:
            showTop(stack,top);
            break;

        default:
            break;
        };

    } while (opt != 5);
    

    return 0;
}
