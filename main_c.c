#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "./functions/loadProvinces.c"
#include "./functions/loadPackageData.c"
#include "structure.h"

void init() {
    loadProvinces();
    loadPackageData();
}


int main(){
    init();

    printf("\nfgdgd %s khkhkjh\n", onGoingPackageData[0].to.provinceNameEn);

    printf("\t\033[1mWelcome to the system!\n\033[0m");
    int n = 1;
    while (1 == 1){
        printf("\n 1.List all ongoing package.\n 2.List all delivered package.\n 3.check a package status.\n 4.change a package status.\n 5.make (a) delivery order(s).\n");
        scanf("%d",&n);
        getchar();

        switch (n){
            case 1:
                printf("\033[1mSure!\033[0m");
                //openAll(0);
                break;
            case 2:
                printf("\033[1mSure!\033[0m");
                //function 2
                break;
            case 3:
                printf("\033[1mSure!\033[0m");
                //function 3
                break;
            case 4:
                printf("\033[1mSure!\033[0m");
                //function 4
                break;
            case 5:
                printf("\033[1mSure!\033[0m");
                //function 5
                break;
            default:
                printf("\033[1m Invalid command, please input the number of command again.\033[0m");
                break;
        }
    }
}