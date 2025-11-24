
ProvinceData *Provinces;

int ProvincesCount;
int count = 0;

void loadProvinces()
{
    int i = 0;
    FILE *provincesFile = fopen(dataPath"provinces.txt", "r");

    if (provincesFile == NULL) {
        printf("Error to Open Provinces file");
        return;
    }

    Provinces = calloc(1, sizeof(ProvinceData));

    while (fscanf(provincesFile, " %d %s", &Provinces[i].provinceCode, Provinces[i].provinceNameEn) != EOF)
    {
        for (int charIndex = 0; Provinces[i].provinceNameEn[charIndex] != '\0'; charIndex++) {
            if (Provinces[i].provinceNameEn[charIndex] == '-') {
                Provinces[i].provinceNameEn[charIndex] = ' ';
            }
        }
        //printf("%d %s\n",Provinces[i].provinceCode, Provinces[i].provinceNameEn);
        
        i++;
        ProvinceData *temp = realloc(Provinces, (i + 1) * sizeof(ProvinceData));
        if (temp == NULL)
            break;
        Provinces = temp;
    }
    ProvinceData *temp = realloc(Provinces, (i) * sizeof(ProvinceData));
    Provinces = temp;

    ProvincesCount = i;
    
    

    fclose(provincesFile);

    return;
}