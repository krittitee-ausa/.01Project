#include <stdio.h>
#include <stdlib.h>




int main(){

    printf("\t\033[1mWelcome to the system!\n\033[0m");
    int n = 1;
    while (n == 1){
    printf("\n 1.List all ongoing package.\n 2.List all delivered package.\n 3.check a package status.\n 4.change a package status.\n 5.make (a) delivery order(s).\n");
    switch (n){
        case 1:
            printf("\033[1mSure!\033[0m");
        case 2:
            printf("\033[1mSure!\033[0m");
        case 3:
            printf("\033[1mSure!\033[0m");
        case 4:
            printf("\033[1mSure!\033[0m");
        case 5:
            printf("\033[1mSure!\033[0m");
        default:
            printf("\033[1m Invalid command, please input the number of command again.\033[0m");
    }
    }
}