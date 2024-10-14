#include <stdio.h>

void printArr(char (*arr)[5], int size){
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            printf("%c  ", (*arr)[j]);
        }
        arr++;
        printf("\n");
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{

    char arr[3][5]= {
        {'m', 'a', 'n', 'o','.'},
        {'l','u','f','f','y'},
        {'z','o','r','o','.'}
        };
    printArr(&arr, 3);
    // arr++;
    return 0;
}
