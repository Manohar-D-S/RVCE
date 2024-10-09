#include <stdio.h>

// int allocateMem(int *q){
//     int *p;
//     p = (int*)malloc(sizeof(int));
//     *p = 20;
//     q = (int*)malloc(sizeof(int));
//     *q = 30;
//     return p;
// }

// int main(int argc, char const *argv[])
// {
//     int *x, *y;
//     x = allocateMem(&y);
//     printf("%d  %d", *x, *y);
//     return 0;
// }


int *allocateMem(int **q){
    int *p;
    p = (int*)malloc(sizeof(int));
    *p = 20;
    *q = (int*)malloc(sizeof(int));
    **q = 30;
    return p;
}

int main(int argc, char const *argv[])
{
    int *x, *y;
    x = allocateMem(&y);
    printf("%d  %d", *x, *y);
    free(x);
    free(y);
    return 0;
}
