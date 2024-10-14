// Program to print factorial of number using recursive function with number of pushes and pops in the function calls.

#include <stdio.h>

int factorial(int num, int* push, int* pop){
    *push += 1;
    if(num == 0 || num == 1){
        *pop += 1;
        return num;}
    else{
        *pop += 1;
        return (num * factorial(num - 1, push, pop));
        }
}

int main(int argc, char const *argv[])
{
    int x = 0, y = 0, n;
    int *push = &x, *pop = &y;
    printf("Enter the number you want to find the facrorial of : ");
    scanf("%d", &n);
    printf("Factorial of %d is %d\n", n, factorial(n, push, pop));

    printf("Pushes = %d \nPops = %d", x, y);
    return 0;
}
