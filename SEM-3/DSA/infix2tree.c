#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define SIZE 30

struct node {
    char data;
    struct node* left;
    struct node* right;
} typedef Node;
typedef Node* NODE;

struct stack {
    NODE list[SIZE];
    int top;
} typedef STACK;

STACK TREE, OPR;

NODE createNode(char c) {
    NODE new = (NODE) malloc(sizeof(Node));
    new->data = c;
    new->left = new->right = NULL;
    return new;
}

NODE pop(STACK* x) {
    return x->list[x->top--];
}

void push(STACK* x, NODE n) {
    x->list[++(x->top)] = n;
}

int precedence(char opr) {
    switch(opr) {
        case '^': case '$':
            return 3;                   // Right associative
        case '*': case '/': case '%':
            return 2;
        case '+': case '-':
            return 1;
        default:
            return 0;                   // Invalid operator
    }
}

void infix(NODE tree) {
    if (tree) {
        if (tree->left || tree->right) printf("(");  
        infix(tree->left);
        printf("%c", tree->data);
        infix(tree->right);
        if (tree->left || tree->right) printf(")");
    }
}

NODE infix2tree(char* expression) {
    TREE.top = -1;
    OPR.top = -1;
    int flag = 0;                                               // Tracks mismatched parentheses

    for (int i = 0; expression[i] != '\0'; i++) {
        char c = expression[i];

        if (isalnum(c)) {
            push(&TREE, createNode(c));
        } else if (c == '(') {
            push(&OPR, createNode(c));
            flag++;
        } else if (c == ')') {
            if (flag <= 0) return NULL;                      // Mismatched closing parentheses
            while (OPR.list[OPR.top]->data != '(') {
                NODE op = pop(&OPR);
                op->right = pop(&TREE);
                op->left = pop(&TREE);
                push(&TREE, op);
            }
            pop(&OPR);                                          // Remove '('
            flag--;
        } else if (strchr("+-*/%^$", c)) {                      // Valid operators
            while (OPR.top != -1 && precedence(OPR.list[OPR.top]->data) >= precedence(c)) {
                NODE op = pop(&OPR);
                op->right = pop(&TREE);
                op->left = pop(&TREE);
                push(&TREE, op);
            }
            push(&OPR, createNode(c));
        } else {
            return NULL;                                        // Invalid character
        }
    }

    if (flag != 0) return NULL;  // Mismatched parentheses

    while (OPR.top != -1) {
        NODE op = pop(&OPR);
        op->right = pop(&TREE);
        op->left = pop(&TREE);
        push(&TREE, op);
    }

    return (TREE.top == 0) ? pop(&TREE) : NULL;  // Return the final tree
}

int main() {
    char expr[50];
    printf("Valid Operators: +, -, *, /, %, ^, $, (, )\n");
    printf("Enter The Infix Expression: ");
    
    if (fgets(expr, sizeof(expr), stdin)) {
        expr[strcspn(expr, "\n")] = '\0';  // Remove trailing newline
    }

    NODE result = infix2tree(expr);
    
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif


    if (!result) {
        printf("You entered an Empty or Incorrect Expression.\n");
        return 0;
    }

    printf("Infix Expression: ");
    infix(result);
    printf("\n");

    return 0;
}
