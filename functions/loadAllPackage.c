

void loadOngoingdata(){
    for(int index = 0; index< dataCount[0];index++){
        //printf("\n\n=== Package Index %d ===\n", index);
        printf("\n\n=== PACKAGE ID %s ===\n", onGoingPackageData[index].id);
        printf("SENDER\t\t: %s\n", onGoingPackageData[index].sender);
        printf("RECEIVER\t: %s\n", onGoingPackageData[index].reciever);
        printf("ID\t\t: %s\n", onGoingPackageData[index].id);
        printf("FROM\t\t: %s\n", onGoingPackageData[index].from.provinceNameEn);
        printf("TO\t\t: %s\n", onGoingPackageData[index].to.provinceNameEn);
        printf("ORDER TIMESTAMP\t: %s\n", ctime(&onGoingPackageData[index].time));
        //printf("=== Package Index %d ===\n", index);
    }
    if (dataCount[0] == 0)printf("\nThere are no package that are in delivery process.\n");
    return;
}


void loadDelivereddata(){

    for(int index = 0; index< dataCount[1];index++){
     //printf("\n\n=== Package Index %d ===\n", index);
     printf("\n\n=== PACKAGE ID %s ===\n", deliveredPackageData[index].id);
        printf("SENDER\t\t: %s\n", deliveredPackageData[index].sender);
        printf("RECEIVER\t: %s\n", deliveredPackageData[index].reciever);
        printf("FROM\t\t: %s\n", deliveredPackageData[index].from.provinceNameEn);
        printf("TO\t\t: %s\n", deliveredPackageData[index].to.provinceNameEn);
        printf("ORDER TIMESTAMP\t: %s", ctime(&deliveredPackageData[index].time));
        printf("DELIVERED\t: %s\n", ctime(&deliveredPackageData[index].deliveredTime));
        //printf("=== Package Index %d ===\n", index);
    }
    if (dataCount[1] == 0)printf("\nThere are no package that are delivered.\n");
    return;
}