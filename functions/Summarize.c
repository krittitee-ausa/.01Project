void summaryDetail(int month, int year) // สรุปย่อยรายเดือน
{
    int counterOnGoing = 0; // จำนวนพัสดุที่กำลังจัดส่งในเดือนนั้นๆ
    for (int index = 0; index < dataCount[0]; index++) // วนซ้ำตามจำนวนพัสดุที่กำลังจัดส่งทั้งหมด
    {

        struct tm *timeinfo;
        timeinfo = localtime(&onGoingPackageData[index].time); // แปลงเวลา time_t ให้เป็น tm เพื่อให้ง่ายต่อการใช้งาน
        if (timeinfo->tm_year + 1900 == year && timeinfo->tm_mon + 1 == month) // ตรวจสอบว่าตรงกับเดือนและปีที่กรอกหรือไม่
        {
            counterOnGoing++; // เพิ่มจำนวน
        }
    }
    int counterDerivered = 0; // จำนวนพัสดุที่จัดส่งสำเร็จในเดือนนั้นๆ
    for (int index = 0; index < dataCount[1]; index++) // วนซ้ำตามจำนวนพัสดุที่จัดส่งสำเร็จทั้งหมด
    {
        struct tm *timeinfo;
        timeinfo = localtime(&deliveredPackageData[index].deliveredTime); // แปลงเวลา time_t ให้เป็น tm เพื่อให้ง่ายต่อการใช้งาน
        if (timeinfo->tm_year + 1900 == year && timeinfo->tm_mon + 1 == month) // ตรวจสอบว่าตรงกับเดือนและปีที่กรอกหรือไม่
        {
            counterDerivered++; // เพิ่มจำนวน
        }
    }
    printf("\nNumber of on going package%s in %d/%d : %d", (counterOnGoing > 1) ? "s" : "", month, year, counterOnGoing); // แสดงผล
    printf("\nNumber of delivered package%s in %d/%d : %d\n", (counterDerivered > 1) ? "s" : "", month, year, counterDerivered); // แสดงผล
}

float deltaDeliverySpeed() // คำนวณความเร็วในการจัดส่งโดยเฉลี่ย
{
    int sumSecs = 0; // ผลรวมของเวลาที่ใช้
    for (int index = 0; index < dataCount[1]; index++) // วนซ้ำตามจำนวนพัสดุที่จัดส่งสำเร็จ
    {
        sumSecs += (deliveredPackageData[index].deliveredTime - deliveredPackageData[index].time); // นำเวลาที่จัดส่งสำเร็จ - เวลาที่เริ่มจัดส่ง
    }

    return ((float)sumSecs / dataCount[1]) / 86400; // หาค่าเฉลี่ย โดยนำผลรวม/จำนวนพัสดุที่จัดส่งสำเร็จ และแปลงหน่วยจากวินาทีให้เป็นวัน
}

void Summarize() // ฟังก์ชันสรุปผล
{
    printf("\n\nNumber of on going package%s: \t%d", (dataCount[0] > 1) ? "s" : "", dataCount[0]); // แสดงจำนวนพัสดุที่กำลังจัดส่งตั้งแต่เริ่มกิจการ
    printf("\nNumber of delivered package%s: \t%d", (dataCount[1] > 1) ? "s" : "", dataCount[1]); // แสดงจำนวนพัสดุที่จัดส่งสำเร็จตั้งแต่เริ่มกิจการ
    printf("\nAverage Delivery Speed: \t%.2f day(s)", deltaDeliverySpeed()); // เวลาที่ใช้จัดส่งโดยเฉลี่ย

    printf("\n\nDo you want to see monthly summary (y/n): "); // ถามว่าต้องการดูสรุปรายเดืิอนไหม
    char Ans;
    int Year;
    int Month;
    scanf(" %c", &Ans);
    if (Ans == 'y') // ต้องการ
    {
        time_t nowTime = time(NULL); // เวลาปัจจุบัน
        struct tm *nowTimeInfo;
        nowTimeInfo = localtime(&nowTime); // แปลงเวลาปัจจุบันให้เป็น struct tm เพื่อให้ง่ายต่อการใช้งาน
        while (1)
        {
            printf("\nYear: "); // กรอกปีที่ต้องการดู
            scanf(" %d", &Year);
            if (Year > nowTimeInfo->tm_year + 1900 || Year < 1) // ตรวจสอบว่าปีที่กรอกเกินปัจจุบันหรือไม่ และน้อยกว่า 1 หรือไม่
            {
                printf("Year %d out of range. Please try again.\n", Year);
            }
            else
            {
                break; // ออกจาก loop การกรอกปี
            }
        }
        while (1)
        {
            printf("Month: "); // กรอกเดือนที่ต้องการดู
            scanf(" %d", &Month);
            if (Year == nowTimeInfo->tm_year + 1900 && Month > nowTimeInfo->tm_mon + 1) // ตรวจสอบว่า เดือนดังกล่าวเกินปัจจุบันหรือไม่
            {
                printf("Out of range. Please try again.\n");
            }
            else if (Month > 12 || Month < 1) // เลขเดือนที่กรอกไม่อยู่ในช่วง [1,12]
            {
                printf("Out of range. Please try again.\n");
            }
            else // ออกจากการกรอกเดือน
            {
                break;
            }
        }

        summaryDetail(Month, Year); // สรุปรายเดือน
    }
}