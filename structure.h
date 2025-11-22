#ifndef myStructure
#define myStructure
#include <time.h>
typedef struct {
    int provinceCode;
    char provinceNameEn[50];
} ProvinceData;
typedef struct{
    char sender[400];
    char reciever[40];
    char id[13];
    ProvinceData from;
    ProvinceData to;
    time_t time;
} package;



#endif
