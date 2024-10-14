#include <stdio.h>
#include <stdlib.h>

int main() {
    int num = 25;
    float deci = 0.0005;
    char man = 'X';

    void *ptr;
    ptr = &num;
    
    printf("%d", *(int*)ptr);
    ptr = &deci;
    // printf("%d", *ptr);
    ptr = &man;
    // printf("%d", *ptr);
    
    

    return 0;
}


/*
Dangling Pointers
Void
NULL
Wild
*/