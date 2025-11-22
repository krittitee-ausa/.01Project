void loadOngoingdata(){
    for(int index = 0; index< dataCount[0];index++){
        printf("\n\n=== Package Index %d ===\n", index);
        printf("SENDER: %s\n", onGoingPackageData[index].sender);
        printf("RECEIVER: %s\n", onGoingPackageData[index].reciever);
        printf("ID: %s\n", onGoingPackageData[index].id);
        printf("FROM: %s\n", onGoingPackageData[index].from.provinceNameEn);
        printf("TO: %s\n", onGoingPackageData[index].to.provinceNameEn);
        printf("ORDER TIMESTAMP: %s\n", ctime(&onGoingPackageData[index].time));
        printf("=== Package Index %d ===\n", index);
    }
}


void loadDelivereddata(){
    for(int index = 0; index< dataCount[1];index++){
        printf("\n\n=== Package Index %d ===\n", index);
        printf("SENDER: %s\n", deliveredPackageData[index].sender);
        printf("RECEIVER: %s\n", deliveredPackageData[index].reciever);
        printf("ID: %s\n", deliveredPackageData[index].id);
        printf("FROM: %s\n", deliveredPackageData[index].from.provinceNameEn);
        printf("TO: %s\n", deliveredPackageData[index].to.provinceNameEn);
        printf("ORDER TIMESTAMP: %s", ctime(&deliveredPackageData[index].time));
        printf("DELIVERED TIMESTAMP: %s\n", ctime(&deliveredPackageData[index].deliveredTime));
        printf("=== Package Index %d ===\n", index);
    }
}