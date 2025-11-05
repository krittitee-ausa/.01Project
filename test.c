#include <stdio.h>
#include <time.h>
#include <string.h>
int main(){
    printf("\t\033[1mWelcome to the system!\n\033[0m");
    printf("\n 1.List all ongoing package.\n 2.List all delivered package.\n 3.check a package status.\n 4.change a package status.\n 5.make (a) delivery order(s).\n");
    int answer;
    printf("Please enter a command's number : ");
    scanf("%d",&answer);
    printf("sure!, loading...\n");
    getchar();
    //printf("Alice   Dan Bangkok Samut Sakhon    123456789   12:30   June 28\nAlicd   Dan Bangkok Samut Sakhon    123456789   12:30   June 28");
    char confirmation = 'N';
    char name[100];
    char name2[100];
    char d1[100];
    char d2[100];
    while (confirmation != 'Y'){
        printf("please enter your name : ");
        fgets(name,100,stdin);
        name[strlen(name)-1 ] = '\0';
        printf("please enter the reciever name : ");
        fgets(name2,100,stdin);
        name2[strlen(name2)-1 ] = '\0';
        printf("please enter the post office where you are now : ");
        fgets(d1,100,stdin);
        d1[strlen(d1)-1 ] = '\0';
        printf("please enter your package destination : ");
        fgets(d2,100,stdin);
        d2[strlen(d2)-1 ] = '\0';
        printf("sender name : %s\nreciever name : %s\npre-destination : %s\npost-destination : %s",name,name2,d1,d2);
        printf("\n is this correct? (Y/N) : ");
        scanf("%c",&confirmation);

    }
    printf("success!");
}