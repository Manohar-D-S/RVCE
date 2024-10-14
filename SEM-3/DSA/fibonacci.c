/*Program for printing fibonacci series*/

#include <stdio.h>

int fibonacci(int n){
    if(n == 0 || n == 1)
        return n;
    else
        return(fibonacci(n-2) + fibonacci(n-1));
}

int main(int argc, char const *argv[])
{
    int num, result, i = 0;
    printf("Choose from the options below:\n1)Print 'n' number of fibonacci terms\n2)Print fibonacci till....\n\nOPTION : ");
    scanf("%d", &num);
    
    switch (num)
    {
    case 1:
        printf("Number of terms to print : "); scanf("%d", &num);
        for (i = 0; i < num; i++)
        {
            printf("%d\n", fibonacci(i));
        }
        break;
    
    case 2:
        printf("Number to print till : "); scanf("%d", &num);
            while(1){
                result = fibonacci(i);
                if(result > num){
                    break;
                } else {
                    printf("%d\t", result);
                    i++;
                }
        }
        break;
    
    default:
        printf("Invalid Option!!!");
        break;
    }
     
    return 0;
}
