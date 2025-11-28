typedef struct
{
    char name[50];
    int index;

} lowercaseP;
int provinceIndex[2];
lowercaseP *lowercaseProvinces;

int stringCompare(char str1[], char str2[]) // เปรียบเทียบ string (เว้นวรรคไม่มีผล ) ใช้เปรียบเทียบจังหวัด
{
    int strConst1 = 0, strConst2 = 0;
    for (int i = 0; i < strlen(str1) - strConst1 || i < strlen(str2) - strConst2; i++)
    {
        if (str1[i + strConst1] == ' ')
        {
            do
            {
                strConst1++;
            } while (str1[i + strConst1] == ' ');
        }

        if (str2[i + strConst2] == ' ')
        {
            strConst2++;
        }
        if (str1[i + strConst1] != str2[i + strConst2])
        {
            return 1;
        }
    }
    return 0;
}

int lowercase(char str[], int *index) // ทำให้เป็นตัวพิมพ์เล็ก และตรวจสอบว่าตรงกับชื่อจังหวัดไหม
{
    char str2[] = "see all provinces";
    if (strcmp(str, str2) == 0) // ถ้าคำนั้นคือ see all provinces
    {
        for (int i = 0; i < ProvincesCount; i++) // แสดงรายชื่อจังหวัด
        {
            printf("%s\n", Provinces[i].provinceNameEn);
        }
        printf("\n please input the province again : ");
    }
    else
    {
        for (int i = 0; i < strlen(str); i++) // วนซ้ำตัวอักษร
        {
            if (str[i] <= 90 && str[i] >= 65) // ถ้าอยู่ในช่วงของตัวพิมพ์ใหญ่
            {
                str[i] += 32; // เปลี่ยนให้เป็นตัวพิมพ์เล็ก โดยตาม ASCII ตัวพิมพ์เล็กอยู่มากกว่าพิมพ์ใหญ่อยู่ 35
            }
        }
        for (int i = 0; i < ProvincesCount; i++) // วนซ้ำเพื่อตรวจสอบว่าตรงกับจังหวัดไหน
        {
            if (stringCompare(str, lowercaseProvinces[i].name) == 0) // เปรียบเทียบ ค่าที่กรอกกับชื่อจังหวัด
            {
                *index = i;
                return 1;
            }
        }
        // ไม่เจอ
        printf("invalid provinces, please input the provinces again (type \"see all provinces\" to view all province possible.)\n: ");
    }
    return 0;
}
void readlowercaseProvinces() // เก็บชื่อจังหวัดให้เป็นตัวพิมพ์เล็ก
{
    lowercaseProvinces = calloc(ProvincesCount, sizeof(lowercaseP)); // จองหน่วยความจำ
    for (int i = 0; i < ProvincesCount; i++) // วนว้ำทุกจังหวัด
    {
        strcpy(lowercaseProvinces[i].name, Provinces[i].provinceNameEn); // คัดลอก string
        lowercaseProvinces[i].index = Provinces[i].provinceCode; // เก็บ Province Code
        for (int j = 0; j < strlen(lowercaseProvinces[i].name); j++) // วนซ้ำทุกตัวอักษร
        {
            if (lowercaseProvinces[i].name[j] <= 90 && lowercaseProvinces[i].name[j] >= 65) // ถ้าอยู่ในช่วงของตัวพิมพ์ใหญ่
            {
                lowercaseProvinces[i].name[j] += 32; // ทำให้เป็นตัวพิมพ์เล็ก
            }
        }
    }
}

void NewOrder() // ฟังก์ชันเพิ่มพัสดุ
{
    char buffer[4][50];
    printf("\n what's your name? : ");
    fgets(buffer[0], 50, stdin); // ชื่อผู้ส่ง
    buffer[0][strlen(buffer[0]) - 1] = '\0';

    printf("who do you want to send your package to? : ");
    fgets(buffer[1], 50, stdin); // ชื่อผู้รับ
    buffer[1][strlen(buffer[1]) - 1] = '\0';

    printf("what province are you in? (type \"see all provinces\" to view all province possible.)\n: ");
    fgets(buffer[2], 50, stdin); // จังหวัดต้นทาง
    buffer[2][strlen(buffer[2]) - 1] = '\0';
    while (lowercase(buffer[2], &provinceIndex[0]) == 0) // วนซ้ำและตรวจสอบว่ากรอกชื่อจังหวัดถูกต้อง
    {
        fgets(buffer[2], 50, stdin);
        buffer[2][strlen(buffer[2]) - 1] = '\0';
    }

    printf("and what is the destination's province? (type \"see all provinces\" to view all province possible.)\n: ");
    fgets(buffer[3], 50, stdin); // จังหวัดปลายทาง
    buffer[3][strlen(buffer[3]) - 1] = '\0';
    while (lowercase(buffer[3], &provinceIndex[1]) == 0) // วนซ้ำและตรวจสอบว่ากรอกชื่อจังหวัดถูกต้อง
    {
        fgets(buffer[3], 50, stdin);
        buffer[3][strlen(buffer[3]) - 1] = '\0';
    }
    char ans;
    while (1) // วนซ้ำเพิ่มถามว่าข้อมูลที่กรอกถูกต้องหรือไม่
    {
        printf("\nSENDER : %s \n", buffer[0]);
        printf("RECIEVER : %s \n", buffer[1]);
        printf("FROM : %s \n", Provinces[provinceIndex[0]].provinceNameEn);
        printf("TO : %s \n", Provinces[provinceIndex[1]].provinceNameEn);
        printf("\nis the information correct?(y/n and c to cancel) : ");
        scanf("%c", &ans);
        getchar();
        if (ans == 'y') // ถูกต้อง
        {
            printf("\033[1m\nSuccess! You successfully placed an order!\n\033[0m");
            dataCount[0]++; // เพิ่มจำนวนพัสดุที่กำลังจัดส่ง
            package *temp = realloc(onGoingPackageData, dataCount[0] * sizeof(package)); // จองหน่วยความจำเพิ่ม
            onGoingPackageData = temp; // เปลี่ยนค่าให้ชี้ไปยังที่ที่จองเพิ่ม
            strcpy(onGoingPackageData[dataCount[0] - 1].sender, buffer[0]); // คัดลอกค่าไปเก็บในรายชื่อพัสดุที่กำลังจัดส่ง
            strcpy(onGoingPackageData[dataCount[0] - 1].reciever, buffer[1]); // คัดลอกค่าไปเก็บในรายชื่อพัสดุที่กำลังจัดส่ง
            onGoingPackageData[dataCount[0] - 1].from = Provinces[provinceIndex[0]]; // คัดลอกค่าไปเก็บในรายชื่อพัสดุที่กำลังจัดส่ง
            onGoingPackageData[dataCount[0] - 1].to = Provinces[provinceIndex[1]]; // คัดลอกค่าไปเก็บในรายชื่อพัสดุที่กำลังจัดส่ง
            char strbuffer[11];
            char strbuffer2[13];
            sprintf(strbuffer2, "%d%d", onGoingPackageData[dataCount[0] - 1].from.provinceCode, onGoingPackageData[dataCount[0] - 1].to.provinceCode); // เก็บตัวเลขให้เป็น string
            time_t rawtime;
            sprintf(strbuffer, "%ld", time(&rawtime)); // เก็บตัวเลขให้เป็น string
            strcat(strbuffer2, &strbuffer[4]);
            long tmp[4];
            char *end;
            tmp[0] = strtoll(strbuffer2, &end, 10);
            while (1) // ตรวจสอบและเปลี่ยนค่าหากหมายเลขพัสดุซ้ำ
            {
                int a = 0;
                for (int i = 0; i < dataCount[0] + dataCount[1]; i++)
                {
                    if (i < dataCount[0])
                    {
                        tmp[1] = strtoll(onGoingPackageData[i].id, &end, 10);
                        if (tmp[1] == tmp[0])
                        {
                            tmp[0]++;
                            a = 1;
                            break;
                        }
                    }
                    else if (i >= dataCount[0] && i < dataCount[0] + dataCount[1])
                    {
                        tmp[1] = strtoll(deliveredPackageData[i - dataCount[0]].id, &end, 10);
                        if (tmp[1] == tmp[0])
                        {
                            tmp[0]++;
                            a = 1;
                            break;
                        }
                    }
                    else
                        a = 0;
                }
                if (a == 0)
                    break;
            }
            sprintf(strbuffer2, "%ld", tmp[0]);
            strcpy(onGoingPackageData[dataCount[0] - 1].id, strbuffer2);
            onGoingPackageData[dataCount[0] - 1].time = time(&rawtime); // เก็บค่าเวลาปัจจุบัน
            printf("\nYour package ID is : %s\n", onGoingPackageData[dataCount[0] - 1].id); // แสดงหมายเลขพัสดุ

            return;
        }
        else if (ans == 'n') // กรอกผิด
        {
            int index;
            while (1) // วนซ้ำเพื่อถามว่าต้องการแก้ไขข้อมูลใด
            {
                printf("Which data do you want to edit?\n1. Sender name\n2. Reciever name\n3. your province\n4. destination's province\nYour function : ");
                scanf("%d", &index);
                getchar();
                if (index < 1 || index > 4) // เกินตัวเลือก
                {
                    printf("please input the valid function number\n");
                    continue; // กลับไป while ต่อ
                }
                break; // ออกจาก while
            }
            printf("sure!\nplease input a new data : ");
            fgets(buffer[index - 1], 50, stdin);
            buffer[index - 1][strlen(buffer[index - 1]) - 1] = '\0';
            if (index >= 3) // ถ้าแก้ไขจังหวัด
            {
                while (lowercase(buffer[index - 1], &provinceIndex[index - 3]) == 0) // ตรจสอบชื่อจังหวัด
                {
                    fgets(buffer[index - 1], 50, stdin);
                    buffer[index - 1][strlen(buffer[index - 1]) - 1] = '\0';
                }
            }
            printf("\n");
        }
        else if (ans == 'c') // ยกเลิกการเพิ่มข้อมูล
        {
            printf("cancelling the order.\n Success!\n");
            return;
        }
        else // กรอกไม่ตรงตัวเลือก
        {
            printf("please input the mentioned characters.\n");
        }
    }
}