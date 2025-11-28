void dataSave()
{
    FILE *onGoingPackageFile = fopen(dataPath "onGoingPackage.txt", "w");
    FILE *deliveredPackageFile = fopen(dataPath "DeliveredPackageData.txt", "a");
    FILE *counterFile = fopen(dataPath "counter.txt", "w");
    if (counterFile == NULL || onGoingPackageFile == NULL || deliveredPackageFile == NULL)
    {
        printf("\nunable to open the file to save\n");
    }
    for (int i = 0; i < dataCount[0]; i++)
    {
        if (i != 0)
        {
            fprintf(onGoingPackageFile, "\n");
        }
        fprintf(onGoingPackageFile, "%s\n%s\n%s\n%d\n%d\n%ld", onGoingPackageData[i].sender,
                onGoingPackageData[i].reciever, onGoingPackageData[i].id, onGoingPackageData[i].from.provinceCode,
                onGoingPackageData[i].to.provinceCode, onGoingPackageData[i].time);
    }
    for (int i = dataCount[2]; i < dataCount[1]; i++)
    {
        fprintf(deliveredPackageFile, "\n%s\n%s\n%s\n%d\n%d\n%ld\n%ld", deliveredPackageData[i].sender,
                deliveredPackageData[i].reciever, deliveredPackageData[i].id, deliveredPackageData[i].from.provinceCode,
                deliveredPackageData[i].to.provinceCode, deliveredPackageData[i].time, deliveredPackageData[i].deliveredTime);
    }
    fprintf(counterFile, "%d %d", dataCount[0], dataCount[1]);
    fclose(onGoingPackageFile);
    fclose(deliveredPackageFile);
    fclose(counterFile);
}