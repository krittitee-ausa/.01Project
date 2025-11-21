#include <stdio.h>
#include <stdlib.h>
#include "../structure.h"

#define provincesPath "./data/provinces.txt"

ProvinceData *Provinces;

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

    fclose(provincesFile);

    return;
}