#ifndef myStructure
#define myStructure

typedef struct{
    char sender[400];
    char reciever[40];
    char id[13];
    ProvinceData first;
    ProvinceData end;
    time_t time;
} package;

// --- 1. การสร้างตัวแปรเก็บข้อมูลจังหวัด (Struct) ---
typedef struct {
    int id;
    int provinceCode;
    char provinceNameEn[50];
} ProvinceData;

#endif
