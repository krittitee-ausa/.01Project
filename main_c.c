#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "path.h"
#include "structure.h"

#include loadProvincesPath
#include loadPackageDataPath
#include loadAllPackagePath
#include dataSummarizePath
#include ChangeandCheckStatusPath
#include PlaceNewOrderPath
#include dataSavePath
#include UserSelectPath

void init()
{
    loadProvinces();
    loadPackageData();
    readlowercaseProvinces();
    loadDeliveredPackageData();
}
int main()
{
    init();

    int user_ans;
    char user_buffer[20];
    int cons = 0;
    while (cons == 0)
    {

        printf("\n\t\033[1mWelcome to the system!\n\033[0m\n");
        printf("What are you?\n1. Admin\n2. Customer\n:: ");
        scanf("%d", &user_ans);
        getchar();
        if (user_ans == 1)
        {
            printf("Please enter the password : ");
            fgets(user_buffer, 20, stdin);
            user_buffer[strlen(user_buffer) - 1] = '\0';
            if (strcmp(user_buffer, "CPE888") == 0)
            {
                printf("\n\033[1mWelcome Admin!\033[0m\n");
                cons = 1;
            }
            else
            {
                printf("\nInvalid password, please try again.\n");
            }
        }
        else if (user_ans == 2)
        {
            printf("\n\033[1mWelcome customer!\033[0m\n");
            cons = 2;
        }
        else
            printf("\n\033[1mInvalid input please input your user choice again.\n\033[0m");
    }
    if (cons == 1)
        Admin_POV();
    else
        Customer_POV();
    dataSave();
    return 0;
}