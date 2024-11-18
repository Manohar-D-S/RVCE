#include <stdio.h>
#include<math.h>

/*
A mulit purpose calculator for arithmatic operations and including matrix 

Develop a c program that reads n integers, sort them both ways using
i) bubble sort
ii) selection sort

Develop a c program to search an element using
binary and linear search
*/

int main() {
    // printf(`"Stadard form of Quadratic Equation is ax^2+bx+c = 0\n\n");    
    // printf("Enter the variable values in the order 'a' 'b' 'c' :\n");    
    // int a,b,c, discrimant;
    // scanf("%d%d%d",&a, &b, &c);

    // discrimant = ((b*b)-4*a*c);

    // if(discrimant<0){
    //     printf("No Real roots exits\n");
    // }
    // else if (discrimant==0){
    //     int root1 = ((-b)+sqrt(discrimant))/2*a;
    //     int root2 = ((-b)-sqrt(discrimant))/2*a;
        
    //     printf("Roots are Real and Equal\n");
    //     printf("Root 1 is %d\n",root1);
    //     printf("Root 2 is %d\n",root2);
    // }
    // else{
    //     int root1 = ((-b)+sqrt(discrimant))/2*a;
    //     int root2 = ((-b)-sqrt(discrimant))/2*a;
        
    //     printf("Roots are Real and Distinct\n");
    //     printf("Root 1 is %d\n",root1);
    //     printf("Root 2 is %d\n",root2);
    // }

    int a = 100, b = 2, c =25, d = 4, result;
    printf("a - b = %d\n", a-b);
    printf("b * c = %d\n", b* c);
    printf("a / c = %d\n", a/c);
    printf("a+b*c = %d\n", a +b *c);
    printf("a*b+c*d = %d\n", a*b+c*d);


    
    
    return 0;
}
