#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

//Well am just modifying the original array itself
int mat[4][4];

void *solvMatrix(void *value){
    int thrdNo = *(int*)value;                              // Retrieve integer value passed as void pointer to identify thread/row number
    for(int i = 0; i < 4; i++)
        mat[thrdNo][i] = (int) pow(mat[thrdNo][i], thrdNo+1);
}

int main(int argc, char const *argv[])
{
    system("cls");
    pthread_t tID[4];
    int index[] = {0,1,2,3};

    //Filling the matrix
    for(int r = 0; r < 4; r++){
        printf("Enter the Elements of ROW-%d:\n", r+1);
        for(int c = 0; c < 4; c++)
            scanf("%d", &mat[r][c]);
    }

    //Preview of the matrix
    printf("Preview of the matrix\n");
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++)
            printf("%3d", mat[r][c]);
        printf("\n");
    }

    //Creating threads  
    for(int i = 0; i < 4; i++){
        pthread_create(&tID[i], NULL, solvMatrix, (void*)&index[i]);
        sleep(0.75); 
    }

    for(int i = 0; i < 3; i++) {
        pthread_join(tID[i], NULL);
    }

    printf("Modified Matrix is as follows:\n");
    for(int r = 0; r < 4; r++){
        for(int c = 0; c < 4; c++)
            printf("%4d", mat[r][c]);
        printf("\n");
    }


    return 0;
}
