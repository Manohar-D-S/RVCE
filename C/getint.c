#include <stdio.h>
#include <string.h>
#include <math.h>
#define s 20

int getint(){
    char str[8];
    int num = 0;
    scanf("%s", str);
    for(int i = 0; str[i] >= '0' && str[i] <= '9' && str[i] != '\0'; i++){
        num += pow(10,i) * (str[strlen(str) -1-i] - '0');
    }
    return num;
}

int main(int argc, char const *argv[])
{
    int number = getint();
    printf("%d\n", number);


    return 0;
}
