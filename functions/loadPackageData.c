#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#include "..\structure.h" อันนี้เผื่อคอมใช้ไม่ได้
#include "../structure.h"
//#include "../functions/loadProvinces.c"

//#define counterPath "C:\\Users\\Team\\Documents\\project01\\.01Project\\data\\counter.txt"
//#define onGoingPackagePath "C:\\Users\\Team\\Documents\\project01\\.01Project\\data\\onGoingPackage.txt"
//#define deliveredPackagePath "C:\\Users\\Team\\Documents\\project01\\.01Project\\data\\DeliveredPackageData.txt"

package *onGoingPackageData;
package *deliveredPackageData;
int dataCount[2];

void loadPackageData() {
  FILE *counterFile = fopen(counterPath, "r");
  FILE *ongoingPackageFile = fopen(onGoingPackagePath, "r");
  FILE *deliveredPackageFile = fopen(deliveredPackagePath, "r");



  for (int i = 0;i< 2;i++){
    dataCount[i] = 0;
    fscanf(counterFile, "%d", &dataCount[i]);
  }
  
  printf("%d",dataCount[1]);

  onGoingPackageData = calloc(dataCount[0], sizeof(package));
  deliveredPackageData = calloc(dataCount[1],sizeof(package));
  
  for (int index = 0; index < dataCount[0]; index++) {
    int FromProvinceID;
    int ToProvinceID;
    fscanf(ongoingPackageFile, " %[^\n]\n", onGoingPackageData[index].sender);
    fscanf(ongoingPackageFile, " %[^\n]\n", onGoingPackageData[index].reciever);
    fscanf(ongoingPackageFile, "%s", onGoingPackageData[index].id);
    fscanf(ongoingPackageFile, "%d", &FromProvinceID);
    fscanf(ongoingPackageFile, "%d", &ToProvinceID);
    fscanf(ongoingPackageFile, "%ld", &onGoingPackageData[index].time);


    for (int i=0; i < ProvincesCount; i++) {
      if (FromProvinceID == Provinces[i].provinceCode) {
        onGoingPackageData[index].from = Provinces[i];
      }
      if (ToProvinceID == Provinces[i].provinceCode) {
        onGoingPackageData[index].to = Provinces[i];
      }
    }

    //printf("\n\n=== Package Index %d ===\n", index);
    //printf("SENDER: %s\n", onGoingPackageData[index].sender);
    //printf("RECEIVER: %s\n", onGoingPackageData[index].reciever);
    //printf("ID: %s\n", onGoingPackageData[index].id);
    //printf("FROM: %d\n", FromProvinceID);
    //printf("TO: %d\n", ToProvinceID);
    //printf("TIMESTAMP: %s\n", ctime(&onGoingPackageData[index].time));
    //printf("=== Package Index %d ===\n", index);
  }
  for (int index = 0; index < dataCount[1]; index++) {
    int FromProvinceID;
    int ToProvinceID;
    fscanf(deliveredPackageFile, " %[^\n]\n", deliveredPackageData[index].sender);
    fscanf(deliveredPackageFile, " %[^\n]\n", deliveredPackageData[index].reciever);
    fscanf(deliveredPackageFile, "%s", deliveredPackageData[index].id);
    fscanf(deliveredPackageFile, "%d", &FromProvinceID);
    fscanf(deliveredPackageFile, "%d", &ToProvinceID);
    fscanf(deliveredPackageFile, "%ld", &deliveredPackageData[index].time);
    fscanf(deliveredPackageFile, "%ld", &deliveredPackageData[index].deliveredTime);

    for (int i=0; i < ProvincesCount; i++) {
      if (FromProvinceID == Provinces[i].provinceCode) {
        deliveredPackageData[index].from = Provinces[i];

      }
      if (ToProvinceID == Provinces[i].provinceCode) {
        deliveredPackageData[index].to = Provinces[i];

      }
    }

    //printf("\n\n=== Package Index %d ===\n", index);
    //printf("SENDER: %s\n", deliveredPackageData[index].sender);
    //printf("RECEIVER: %s\n", deliveredPackageData[index].reciever);
    //printf("ID: %s\n", deliveredPackageData[index].id);
    //printf("FROM: %d\n", FromProvinceID);
    //printf("TO: %d\n", ToProvinceID);
    //printf("TIMESTAMP: %s", ctime(&deliveredPackageData[index].time));
    //printf("DELIVERED TIMESTAMP: %s\n", ctime(&deliveredPackageData[index].deliveredTime));
    //printf("=== Package Index %d ===\n", index);

  }


  fclose(ongoingPackageFile);

  return;
}