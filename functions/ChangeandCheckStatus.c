void checkStatus() //ฟังก์ชันตรวจสอบสถานะของพัสดุ
{
    char ID[13];
    printf("\nplease enter your package ID : ");
    scanf("%s", ID);
    getchar();
    for (int index = 0; index < dataCount[0]; index++) // ค้นหาพัสดุที่มี ID ตรงกับที่กรอกจากพัสดุที่กำลังจัดส่ง
    {
        if (strcmp(ID, onGoingPackageData[index].id) == 0) // เจอ
        {
            printf("\n===== PACKAGE FOUND =====\n");
            printf("PACKAGE ID\t: %s\n", onGoingPackageData[index].id);
            printf("SENDER\t\t: %s\n", onGoingPackageData[index].sender);
            printf("RECEIVER\t: %s\n", onGoingPackageData[index].reciever);
            printf("FROM\t\t: %s\n", onGoingPackageData[index].from.provinceNameEn);
            printf("TO\t\t: %s\n", onGoingPackageData[index].to.provinceNameEn);
            printf("ORDER TIMESTAMP\t: %s\n", ctime(&onGoingPackageData[index].time));
            printf("\033[1mPACKAGE STATUS : DELIVERY IN PROGRESS.\n\033[0m");
            printf("==========================\n");
            return; // ออกจากการทำงานในฟังก์ชันนี้
        }
    }
    for (int index = 0; index < dataCount[1]; index++) // ค้นหาพัสดุที่มี ID ตรงกับที่กรอกจากพัสดุที่จัดส่งสำเร็จ
    {
        if (strcmp(ID, deliveredPackageData[index].id) == 0) // เจอ
        {
            printf("\n===== PACKAGE FOUND =====\n");
            printf("PACKAGE ID\t: %s\n", deliveredPackageData[index].id);
            printf("SENDER\t\t: %s\n", deliveredPackageData[index].sender);
            printf("RECEIVER\t: %s\n", deliveredPackageData[index].reciever);
            printf("FROM\t\t: %s\n", deliveredPackageData[index].from.provinceNameEn);
            printf("TO\t\t: %s\n", deliveredPackageData[index].to.provinceNameEn);
            printf("ORDER TIMESTAMP\t: %s", ctime(&deliveredPackageData[index].time));
            printf("DELIVERED\t: %s\n", ctime(&deliveredPackageData[index].deliveredTime));
            printf("\033[1mPACKAGE STATUS : DELIVERED SUCCESSFULLY.\n\033[0m");
            printf("==========================\n");
            return; // ออกจากการทำงานในฟังก์ชันนี้
        }
    }
    printf("\n\033[1mINVALID OR INCORRECT PACKAGE ID, PLEASE CHECK YOUR PACKAGE ID AND TRY AGAIN\033[1m\n"); // ไม่เจอ
    return; // ออกจากการทำงานในฟังก์ชันนี้
}

void changeStatus() // ฟังก์ชันเปลี่ยนสถานะพัสดุ
{
    char ID[13]; // เลข ID ของพัสดุ
    int isChecked = 0; // 1 = เจอ, 0 = ไม่เจอ
    int indexs;
    while (1)
    {
        printf("\nplease enter your package ID : ");
        scanf("%s", ID);
        getchar();
        for (int index = 0; index < dataCount[0]; index++)
        {
            if (strcmp(ID, onGoingPackageData[index].id) == 0)
            {
                printf("\n===== PACKAGE FOUND =====\n");
                printf("PACKAGE ID\t: %s\n", onGoingPackageData[index].id);
                printf("SENDER\t\t: %s\n", onGoingPackageData[index].sender);
                printf("RECEIVER\t: %s\n", onGoingPackageData[index].reciever);
                printf("FROM\t\t: %s\n", onGoingPackageData[index].from.provinceNameEn);
                printf("TO\t\t: %s\n", onGoingPackageData[index].to.provinceNameEn);
                printf("TIMESTAMP\t: %s\n", ctime(&onGoingPackageData[index].time));
                printf("==========================\n");
                isChecked = 1;
                indexs = index;
                break;
            }
        }
        for (int index = 0; index < dataCount[1] && isChecked != 1; index++)
        {
            if (strcmp(ID, deliveredPackageData[index].id) == 0)
            {
                printf("\n===== PACKAGE FOUND =====\n");
                printf("PACKAGE ID\t: %s\n", deliveredPackageData[index].id);
                printf("SENDER\t\t: %s\n", deliveredPackageData[index].sender);
                printf("RECEIVER\t: %s\n", deliveredPackageData[index].reciever);
                printf("FROM\t\t: %s\n", deliveredPackageData[index].from.provinceNameEn);
                printf("TO\t\t: %s\n", deliveredPackageData[index].to.provinceNameEn);
                printf("ORDER TIMESTAMP\t\t: %s", ctime(&deliveredPackageData[index].time));
                printf("DELIVERED TIMESTAMP\t: %s\n", ctime(&deliveredPackageData[index].deliveredTime));
                printf("==========================\n\n");
                printf("\033[1mTHIS PACKAGE IS ALREADY DELIVERED, NO NEED TO CHANGE ITS STATUS ANYMORE.\033[0m\n");
                return;
            }
        }
        if (isChecked == 0)
        {
            printf("\n\033[1mINVALID OR INCORRECT PACKAGE ID, PLEASE CHECK YOUR PACKAGE ID AND TRY AGAIN\033[0m\n");
            return;
        }
        break;
    }

    char ans;
    printf("Is this the data of a package you want to change its status?(y/n) : ");
    scanf("%c", &ans);
    getchar();
    if (ans == 'y')
    {
        printf("are you sure you want to change this package status?(y/n) : ");
        scanf("%c", &ans);
        getchar();
        if (ans == 'y')
        {
            dataCount[1]++;
            package *temp = realloc(deliveredPackageData, dataCount[1] * sizeof(package));
            deliveredPackageData = temp;
            deliveredPackageData[dataCount[1] - 1] = onGoingPackageData[indexs];
            time_t rawtime;
            deliveredPackageData[dataCount[1] - 1].deliveredTime = time(&rawtime);
            for (int i = indexs; i < dataCount[0] - 1; i++)
            {
                onGoingPackageData[i] = onGoingPackageData[i + 1];
            }
            memset(&onGoingPackageData[dataCount[0] - 1], 0, sizeof(package));
            printf("SUCCESS\n");
            dataCount[0]--;
        }
        else
        {
            printf("UNDERSTOOD.\n");
        }

        return;
    }
    else if (ans == 'n')
    {
        printf("If in that case, please check the package ID and try again later.\n");
        return;
    }
    else
    {
        printf("Invalid answer please try again later.\n");
        return;
    }
}