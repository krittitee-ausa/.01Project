
ProvinceData *Provinces;

int ProvincesCount;
int count = 0;

void loadProvinces() // อ่านค่าจังหวัดจากไฟล์ และเก็บใน Provinces
{
    int i = 0;
    FILE *provincesFile = fopen(dataPath "provinces.txt", "r"); // เปิดไฟล์

    if (provincesFile == NULL) // เปิดไฟล์ไม่สำเร็จ
    {
        printf("Error to Open Provinces file");
        return;
    }

    Provinces = calloc(1, sizeof(ProvinceData)); // จองหน่วยความจำ

    while (fscanf(provincesFile, " %d %s", &Provinces[i].provinceCode, Provinces[i].provinceNameEn) != EOF) // วนซ้ำจนกว่าจะจบไฟล์
    {
        for (int charIndex = 0; Provinces[i].provinceNameEn[charIndex] != '\0'; charIndex++) // วนซ้ำแต่ละตัวอักษรเพื่อเปลี่ยนตัวอักษรจาก '-' เป็น ' ' เว้นวรรค
        {
            if (Provinces[i].provinceNameEn[charIndex] == '-')
            {
                Provinces[i].provinceNameEn[charIndex] = ' ';
            }
        }

        i++;
        ProvinceData *temp = realloc(Provinces, (i + 1) * sizeof(ProvinceData)); // จองหน่วยความจำเพิ่ม
        if (temp == NULL) // จองเพิ่มไม่สำเร็จ
            break;
        Provinces = temp;
    }
    ProvinceData *temp = realloc(Provinces, (i) * sizeof(ProvinceData)); // จองหน่วยความจำเพิ่ม
    Provinces = temp;

    ProvincesCount = i; // เก็บจำนวนจังหวัด

    fclose(provincesFile); // ปิดไฟล์

    return;
}