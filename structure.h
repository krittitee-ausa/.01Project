#ifndef myStructure
#define myStructure

typedef struct{
    char name[20];
    char postcode[7];
} town_info;

typedef struct{
    char sender[400];
    char reciever[40];
    char id[13];
    town_info first;
    town_info end;
    long long int time;
} package;

#endif
