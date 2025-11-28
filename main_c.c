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

    int user_ans; // เก็บคำตอบว่าเป็นลูกค้าหรือผู้ดูแล
    char user_buffer[20]; // เก็บรหัส
    while (1)
    {

        printf("\n\t\033[1mWelcome to the system!\n\033[0m\n");
        printf("What are you?\n1. Admin\n2. Customer\n:: ");
        scanf("%d", &user_ans);
        getchar();
        if (user_ans == 1) // เข้าเมนูผู้ดูแลระบบ
        {
            printf("Please enter the password : "); 
            fgets(user_buffer, 20, stdin); // ให้กรอกรหัส
            user_buffer[strlen(user_buffer) - 1] = '\0';
            if (strcmp(user_buffer, "CPE888") == 0) // เปรียบเทียบว่ารหัสที่กรอกใช่ CPE888 ไหม
            {
                printf("\n\033[1mWelcome Admin!\033[0m\n");
                Admin_POV(); // อยู่ในไฟล์ ./functions/User_select.c
                break;
            }
            else // กรอกรหัสผิด
            {
                printf("\nInvalid password, please try again.\n");
            }
        }
        else if (user_ans == 2) // เมนูลูกค้า
        {
            printf("\n\033[1mWelcome customer!\033[0m\n");
            Customer_POV(); // อยู่ในไฟล์ ./functions/User_select.c
            break;
        }
        else // กรอกตัวเลือกผิด
            printf("\n\033[1mInvalid input please input your user choice again.\n\033[0m");
    }
    dataSave(); // บันทึกข้อมูลเมื่อปิดการทำงานของโปรแกรม
    return 0;
}