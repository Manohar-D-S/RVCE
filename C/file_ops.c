#include <stdio.h>
#include <sysexits.h>

int main(int argc, char const *argv[])
{
    FILE *fileS, *fileD;

/*    file = fopen("/home/manohar/scholarshipRequest.txt", "r");    //read from a file and write in stdout

    while(1){
        char c = fgetc(file);
        if(c == EOF)
            break; 
        printf("%c", c);

        }*/

    /*fileS = fopen("/home/manohar/Anime.txt", "r");    //read from a file and write in another file
    fileD = fopen("/home/manohar/copid.txt", "w+");

    char c[50];
    fgets(c, 50, fileS);                    //still testing
    while(c){
        fputs(c,fileS);
        fputs("\n", fileS);
        fgets(c, 50, fileS);
    }
    return 0;*/

    char onemore = 'y';
    struct emp
    {
        char name[50];
        int sal;
        char married;
    } typedef empl;
    
    empl list1;
    
    fileD = fopen("list.txt", "r");

    /*while(onemore == 'Y' || onemore == 'y'){
        printf("Enter name salary and marital status[y/n] : ");
        scanf("%s %d %c", list1.name, &list1.sal, &list1.married);
        if(list1.married != 'y' && list1.married != 'n'){
            printf("Worng bastard : ");
            scanf("%c", list1.married);
        }
        fprintf(fileD, "%s %d %c\n", list1.name, list1.sal, list1.married);
        printf("Want to enter another data u idiot ? [y/n]");
        fflush(stdin);
        scanf("%c", &onemore);
    }*/

//    while (fscanf(fileD, "%s %d %c", list1.name, &list1.sal, &list1.married) != EOF)
//    {
//     printf("\n%s %d %c", list1.name, list1.sal, list1.married);
//    }
}
