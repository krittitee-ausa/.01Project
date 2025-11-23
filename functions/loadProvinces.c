#include <stdio.h>
#include <stdlib.h>
//#include "..\structure.h" อันนี้เผื่อคอมใช้ไม่ได้
#include "../structure.h"
#define provincesPath "C:\\Users\\Team\\Documents\\project01\\.01Project\\data\\provinces.txt"

ProvinceData *Provinces;
int ProvincesCount;

void loadProvinces()
{
    int i = 0;
    FILE *provincesFile = fopen(provincesPath, "r");

    if (provincesFile == NULL) {
        printf("Error to Open file");
        return;
    }

    Provinces = calloc(1, sizeof(ProvinceData));

    while (fscanf(provincesFile, " %d %s", &Provinces[i].provinceCode, Provinces[i].provinceNameEn) != EOF)
    {
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