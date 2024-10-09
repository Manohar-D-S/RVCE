#include <stdio.h>
#include <stdlib.h>

int binSrch(int list[], int low, int high, int key){
    if(low <= high){
        int mid = (low + high) / 2;
        if(list[mid] == key)
            return mid;
        else if (key < list[mid])
            binSrch(list, low, (mid-1), key);
        else
            binSrch(list, (mid+1), high, key);
    } else {
        return NULL;
    }
}

int compare(const void* a, const void* b){
    return (*(int*)a - *(int*)b);
}

int main(int argc, char const *argv[])
{
    int list[6], key;
    printf("Enter the numbers of the array : ");
    for (int i = 0; i < 6; i++)
    {
        scanf("%d", &list[i]);
    }

    qsort(list,6,sizeof(int),compare);
    for (int i = 0; i < 6; i++)
        printf("%d\t", list[i]);
    
    printf("\nEnter the element to search : "); scanf("%d", &key);
    int result = binSrch(list,0,6,key);
    if( result )
        printf("\n\nElement %d found at index %d.", key, result + 1);
    else
        printf("\n\nElement not found");

    return 0;
}
