#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "structure.h"

void reset(FILE* file, int*i){
    rewind(file);
    *i = 0;
}

void openAll(int choice) {
    switch (choice){
        case 0:
            int count = 0;
            int i = 0;
            FILE* counter = fopen("counter.txt", "r+");
            FILE* ongoing = fopen("ongoingPackage.txt", "r+");
            fscanf(counter, "%d", &count);
            printf("%d", count);

            package *packages = calloc(1, sizeof(package));

            long long int TIME_INFILE;
            int FirstID, EndID;
            char Sender[]
            while (fscanf(ongoing, "%s %s %s %d %d %lld", packages[i].sender, packages[i].reciever, packages[i].id, &FirstID, &EndID, &TIME_INFILE) != EOF){
                i++;
                package *temp = realloc(packages, (i+1)*sizeof(package));
                if (temp == NULL) break;
                packages = temp;
            }
            printf("\nsuccess");
            reset(ongoing,&i);
            while (i < count){
                printf("%s",packages[i].sender);
                i++;
            }
            break;
        case 1:
            printf("wait a min");
            break;
        default:
            printf("\033[1m Invalid!! \033[0m");
            break;
    }
}