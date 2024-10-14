#include <stdio.h>
#include <strings.h>
#include <string.h>

/* Count the numbers of vowels, consonants, digits, white spaces, and other characters in that line of text*/

void toLower(char *string){
    for (int i = 0; *(string + i) != '\0'; i++)
    {
        if(*(string + i) >= 'A' && *(string + i) <= 'Z'){
                *(string + i) += 32;
            }
    }
    
}


int main(int argc, char const *argv[])
{
    int vowel = 0, cons = 0 , ws = 0, digi=0, oth = 0;
    char arr[50];
    char *str = arr;
    printf("Enter the text : ");    scanf("%[^\n]",arr);

    toLower(str);

    for(int i = 0; *(str + i) != '\0';i++){
        if(*(str + i) >= 'a' && *(str + i) <= 'z'){
            if(*(str + i) == 'a' || *(str + i) == 'e' ||*(str + i) == 'i' ||*(str + i) == 'o' ||*(str + i) == 'u' ){
                vowel++;
            } else {
                cons++;
            }        
        } else if(*(str + i) == ' '){
            ws++;
        } else if (*(str + i) >= '0' && *(str + i) <= '9')
        {
            digi++;
        } else {
            oth++;
        }
    }

    
    printf("Text : %s\n", str);
    printf("Vowels = %d\nConsonants = %d\nDigits = %d\nWhite_Spaces = %d\nOther = %d\n", vowel, cons, digi,ws,oth);
    
    return 0;
}
