void dataSave() // บันทึกข้อมูล
{
    FILE *onGoingPackageFile = fopen(dataPath "onGoingPackage.txt", "w"); // เปิดไฟล์
    FILE *deliveredPackageFile = fopen(dataPath "DeliveredPackageData.txt", "a"); // เปิดไฟล์
    FILE *counterFile = fopen(dataPath "counter.txt", "w"); // เปิดไฟล์
    if (counterFile == NULL || onGoingPackageFile == NULL || deliveredPackageFile == NULL) // เปิดไฟล์ไม่สำเร็จ
    {
        printf("\nunable to open the file to save\n");
    }
    // บันทึก กำลังจัดส่ง
    for (int i = 0; i < dataCount[0]; i++) // วนซ้ำตามจำนวนพัสดุที่กำลังจัดส่ง
    {
        if (i != 0) // ถ้า i ไม่เป็น 0 
        {
            fprintf(onGoingPackageFile, "\n"); // ให้ขึ้นบรรทัดใหม่ในไฟล์
        }
        // เขียนค่าข้อมูลพัสดุไปในไฟล์ onGoingPackage.txt
        fprintf(onGoingPackageFile, "%s\n%s\n%s\n%d\n%d\n%ld", onGoingPackageData[i].sender,
                onGoingPackageData[i].reciever, onGoingPackageData[i].id, onGoingPackageData[i].from.provinceCode,
                onGoingPackageData[i].to.provinceCode, onGoingPackageData[i].time);
    }
    // บันทึก จัดส่งสำเร็จ
    for (int i = dataCount[2]; i < dataCount[1]; i++)
    {
        // เขียนค่าข้อมูลพัสดุไปในไฟล์ DeliveredPackageData.txt
        fprintf(deliveredPackageFile, "\n%s\n%s\n%s\n%d\n%d\n%ld\n%ld", deliveredPackageData[i].sender,
                deliveredPackageData[i].reciever, deliveredPackageData[i].id, deliveredPackageData[i].from.provinceCode,
                deliveredPackageData[i].to.provinceCode, deliveredPackageData[i].time, deliveredPackageData[i].deliveredTime);
    }
    fprintf(counterFile, "%d %d", dataCount[0], dataCount[1]); // เขียนค่าจำนวนในไฟล์ counter.txt
    fclose(onGoingPackageFile); // ปิดไฟล์
    fclose(deliveredPackageFile); // ปิดไฟล์
    fclose(counterFile); // ปิดไฟล์
}