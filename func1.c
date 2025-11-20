#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

void reset(FILE* file, int*i){
    rewind(file);
    *i = 0;
}

void openAll(int choice) {
    switch (choice){
        case 0:
            int count = 0;
            FILE* counter = fopen("counter.txt", "r+");
            fscanf(counter, "%d", &count);
            printf("%d", count);

            /*while (fscanf(ongoing,"%s",packages[i].sender) != EOF){
                i++;
            }
            printf("success");
            reset(ongoing,&i);
            while (i < counts){
                
                printf("%s",packages[i].sender);
                i++;
            }
            break;
        case 1:
            printf("wait a min");
            break;
        default:
            printf("\033[1m Invalid!! \033[0m");
            break;*/
    }
}