void summaryDetail(int month, int year)
{
    int counterOnGoing = 0;
    for (int index = 0; index < dataCount[0]; index++)
    {

        // printf("ORDER TIMESTAMP\t: %s\n", ctime(&onGoingPackageData[index].time));
        struct tm *timeinfo;
        timeinfo = localtime(&onGoingPackageData[index].time);
        // printf("--%d %d--", timeinfo->tm_year, timeinfo->tm_mon);
        if (timeinfo->tm_year + 1900 == year && timeinfo->tm_mon + 1 == month)
        {
            counterOnGoing++;
        }
    }
    int counterDerivered = 0;
    for (int index = 0; index < dataCount[1]; index++)
    {

        // printf("ORDER TIMESTAMP\t: %s\n", ctime(&onGoingPackageData[index].time));
        struct tm *timeinfo;
        timeinfo = localtime(&deliveredPackageData[index].deliveredTime);
        // printf("--%d %d--", timeinfo->tm_year, timeinfo->tm_mon);
        if (timeinfo->tm_year + 1900 == year && timeinfo->tm_mon + 1 == month)
        {
            counterDerivered++;
        }
    }
    printf("\nNumber of on going package%s in %d/%d : %d", (counterOnGoing > 1) ? "s" : "", month, year, counterOnGoing);
    printf("\nNumber of delivered package%s in %d/%d : %d\n", (counterDerivered > 1) ? "s" : "", month, year, counterDerivered);
}

float deltaDeliverySpeed()
{
    int sumSecs = 0;
    for (int index = 0; index < dataCount[1]; index++)
    {
        sumSecs += (deliveredPackageData[index].deliveredTime - deliveredPackageData[index].time);
    }

    return ((float)sumSecs / dataCount[1]) / 86400;
}

void Summarize()
{
    printf("\n\nNumber of on going package%s: \t%d", (dataCount[0] > 1) ? "s" : "", dataCount[0]);
    printf("\nNumber of delivered package%s: \t%d", (dataCount[1] > 1) ? "s" : "", dataCount[1]);
    printf("\nAverage Delivery Speed: \t%.2f day(s)", deltaDeliverySpeed());

    printf("\n\nDo you want to see monthly summary (y/n): ");
    char Ans;
    int Year;
    int Month;
    scanf(" %c", &Ans);
    if (Ans == 'y')
    {
        time_t nowTime = time(NULL);
        struct tm *nowTimeInfo;
        nowTimeInfo = localtime(&nowTime);
        while (1)
        {
            printf("\nYear: ");
            scanf(" %d", &Year);
            if (Year > nowTimeInfo->tm_year + 1900 || Year < 1)
            {
                printf("Year %d out of range. Please try again.\n", Year);
            }
            else
            {
                break;
            }
        }
        while (1)
        {
            printf("Month: ");
            scanf(" %d", &Month);
            if (Year == nowTimeInfo->tm_year + 1900 && Month > nowTimeInfo->tm_mon + 1)
            {
                printf("Out of range. Please try again.\n");
            }
            else if (Month > 12 || Month < 1)
            {
                printf("Out of range. Please try again.\n");
            }
            else
            {
                break;
            }
        }

        summaryDetail(Month, Year);
    }
}