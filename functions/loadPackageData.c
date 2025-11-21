#include <stdio.h>
#include <stdlib.h>
#include "../structure.h"

#define counterPath "./data/counter.txt"
#define onGoingPackagePath "./data/onGoingPackage.txt"

package *onGoingPackageData;

int main() {
  FILE *counterFile = fopen(counterPath, "r");
  FILE *ongoingPackageFile = fopen(onGoingPackagePath, "r");

  int dataCount = 0;
  fscanf(counterFile, "%d", &dataCount);

  onGoingPackageData = calloc(dataCount, sizeof(package));

  for (int index = 0; index < dataCount; index++) {
    int FromProvinceID;
    int ToProvinceID;
    long long int TimeStamp;
    fscanf(ongoingPackageFile, " %[^\n]\n", onGoingPackageData[index].sender);
    fscanf(ongoingPackageFile, " %[^\n]\n", onGoingPackageData[index].reciever);
    fscanf(ongoingPackageFile, "%s", onGoingPackageData[index].id);
    fscanf(ongoingPackageFile, "%d", &FromProvinceID);
    fscanf(ongoingPackageFile, "%d", &ToProvinceID);
    fscanf(ongoingPackageFile, "%lld", &TimeStamp);

    //printf("\n\n=== Package Index %d ===\n", index);
    //printf("SENDER: %s\n", onGoingPackageData[index].sender);
    //printf("RECEIVER: %s\n", onGoingPackageData[index].reciever);
    //printf("ID: %s\n", onGoingPackageData[index].id);
    //printf("FROM: %d\n", FromProvinceID);
    //printf("TO: %d\n", ToProvinceID);
    //printf("TIMESTAMP: %lld\n", TimeStamp);
    //printf("=== Package Index %d ===\n", index);
  }

  fclose(ongoingPackageFile);
}