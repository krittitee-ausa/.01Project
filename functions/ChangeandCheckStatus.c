//package *onGoingPackageData;
//package *deliveredPackageData;

void checkStatus(){
    char ID[13];
    printf("\nplease enter your package ID : ");
    scanf("%s",ID);
    getchar();
    for (int index = 0;index < dataCount[0];index++){
        if (strcmp(ID,onGoingPackageData[index].id) == 0){
            printf("SENDER: %s\n", onGoingPackageData[index].sender);
            printf("RECEIVER: %s\n", onGoingPackageData[index].reciever);
            printf("ID: %s\n", onGoingPackageData[index].id);
            printf("FROM: %s\n", onGoingPackageData[index].from.provinceNameEn);
            printf("TO: %s\n",  onGoingPackageData[index].to.provinceNameEn);
            printf("TIMESTAMP: %s\n", ctime(&onGoingPackageData[index].time));
            printf("\033[1mPACKAGE STATUS : DELIVERY IN PROGRESS.\n\033[0m");
            return;
        }
        
    }
    for (int index = 0;index < dataCount[1];index++){
        if (strcmp(ID,deliveredPackageData[index].id) == 0){
            printf("SENDER: %s\n", deliveredPackageData[index].sender);
            printf("RECEIVER: %s\n", deliveredPackageData[index].reciever);
            printf("ID: %s\n", deliveredPackageData[index].id);
            printf("FROM: %s\n", deliveredPackageData[index].from.provinceNameEn);
            printf("TO: %s\n", deliveredPackageData[index].to.provinceNameEn);
            printf("ORDER TIMESTAMP: %s", ctime(&deliveredPackageData[index].time));
            printf("DELIVERED TIMESTAMP: %s\n", ctime(&deliveredPackageData[index].deliveredTime));
            printf("\033[1mPACKAGE STATUS : DELIVERED SUCCESSFULLY.\n\033[0m");
            return;
        }
        
    }
    printf("\n\033[1mINVALID OR INCORRECT PACKAGE ID, PLEASE CHECK YOUR PACKAGE ID AND TRY AGAIN\033[1m\n");
    return;
}

void changeStatus(){
    char ID[13];
    int isChecked = 0;
    while(1){
        printf("\nplease enter your package ID : ");
        scanf("%s",ID);
        getchar();
        for (int index = 0;index < dataCount[0];index++){
            if (strcmp(ID,onGoingPackageData[index].id) == 0){
                printf("SENDER: %s\n", onGoingPackageData[index].sender);
                printf("RECEIVER: %s\n", onGoingPackageData[index].reciever);
                printf("ID: %s\n", onGoingPackageData[index].id);
                printf("FROM: %s\n", onGoingPackageData[index].from.provinceNameEn);
                printf("TO: %s\n",  onGoingPackageData[index].to.provinceNameEn);
                printf("TIMESTAMP: %s\n", ctime(&onGoingPackageData[index].time));
                isChecked = 1;
                break;
            } 
        }
        for (int index = 0;index < dataCount[1] && isChecked != 1;index++){
            if (strcmp(ID,deliveredPackageData[index].id) == 0){
                printf("SENDER: %s\n", deliveredPackageData[index].sender);
                printf("RECEIVER: %s\n", deliveredPackageData[index].reciever);
                printf("ID: %s\n", deliveredPackageData[index].id);
                printf("FROM: %s\n", deliveredPackageData[index].from.provinceNameEn);
                printf("TO: %s\n", deliveredPackageData[index].to.provinceNameEn);
                printf("ORDER TIMESTAMP: %s", ctime(&deliveredPackageData[index].time));
                printf("DELIVERED TIMESTAMP: %s\n", ctime(&deliveredPackageData[index].deliveredTime));
                isChecked = 1;
                break;
                }
            
            }
            if (isChecked == 0){
                printf("\n\033[1mINVALID OR INCORRECT PACKAGE ID, PLEASE CHECK YOUR PACKAGE ID AND TRY AGAIN\033[1m\n");
                return;
        
            }
            break;
        }
        
    char ans;
    printf("Is this the data of a package you want to change its status?(y/n) : ");
    scanf("%c",&ans);
    getchar();
    if (ans == 'y'){
        printf("are you sure you want to change this package status?(y/n) : ");
        scanf("%c",&ans);
        getchar();
        return;
    }
    else if (ans == 'n'){
        printf("If in that case, please check the package ID and try again later.\n");
        return;
    }
    else{
        printf("Invalid answer please try again later.\n");
        return;
    }
}