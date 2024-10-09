#include <stdio.h>

int main(int argc, char const *argv[])
{
    // int *p;
    // int array[5] = {2,4,6,8,10};
    // int mat[5] = {1,3,5,7,9};

    // p = array;
    // printf("%u\t%d\n", p, *p);

    // p += 1;
    // printf("%u\t%d\n", p, *p);

    // int *q = ++p;
    // printf("%d\t%u\n", *q, q);
    // printf("%u\t%d\n", p, *p);

    int x = 150, y = 200;
    
    const int *ptr = &x;    //the value to which the pointer is being pointed becomes constant          (Pointer to a constant)

    printf("%u\n", ptr);
    ptr = &y;
    printf("%u\n", ptr);
    // *ptr = 1000;  

    int *const qtr = &y; // The pointer itself is constant (Constant Pointer)
    // qtr = &x;

    int *const *man = &x;
    man = &y;
    *man = 1500;

    return 0;
}
cls
