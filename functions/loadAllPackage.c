

void loadOngoingdata() // แสดงข้อมูลพัสดุที่กำลังจัดส่งทั้งหมด
{
    for (int index = 0; index < dataCount[0]; index++) // วนซ้ำตามจำนวน
    {
        printf("\n\n=== PACKAGE ID %s ===\n", onGoingPackageData[index].id);
        printf("SENDER\t\t: %s\n", onGoingPackageData[index].sender);
        printf("RECEIVER\t: %s\n", onGoingPackageData[index].reciever);
        printf("FROM\t\t: %s\n", onGoingPackageData[index].from.provinceNameEn);
        printf("TO\t\t: %s\n", onGoingPackageData[index].to.provinceNameEn);
        printf("ORDER TIMESTAMP\t: %s\n", ctime(&onGoingPackageData[index].time));
    }
    if (dataCount[0] == 0) // ไม่มีพัสดุที่กำลังจัดส่ง
        printf("\nThere are no package that are in delivery process.\n");
    return;
}

void loadDelivereddata() // แสดงข้อมูลพัสดุที่จัดส่งสำเร็จทั้งหมด
{

    for (int index = 0; index < dataCount[1]; index++) // วนซ้ำตามจำนวน
    {
        printf("\n\n=== PACKAGE ID %s ===\n", deliveredPackageData[index].id);
        printf("SENDER\t\t: %s\n", deliveredPackageData[index].sender);
        printf("RECEIVER\t: %s\n", deliveredPackageData[index].reciever);
        printf("FROM\t\t: %s\n", deliveredPackageData[index].from.provinceNameEn);
        printf("TO\t\t: %s\n", deliveredPackageData[index].to.provinceNameEn);
        printf("ORDER TIMESTAMP\t: %s", ctime(&deliveredPackageData[index].time));
        printf("DELIVERED\t: %s\n", ctime(&deliveredPackageData[index].deliveredTime));
    }
    if (dataCount[1] == 0) // ไม่มีพัสดุที่จัดส่งสำเร็จ
        printf("\nThere are no package that are delivered.\n");
    return;
}