package *onGoingPackageData;
package *deliveredPackageData;
int dataCount[2];
#include <stdio.h>
#include <time.h> // Required for clock() function

clock_t start_time, end_time;
double time_spent;


void loadPackageData() {
  FILE *counterFile = fopen(dataPath"counter.txt", "r");
  FILE *ongoingPackageFile = fopen(dataPath"onGoingPackage.txt", "r");
  



  /*for (int i = 0;i< 2;i++){
    dataCount[i] = 0;
    fscanf(counterFile, "%d", &dataCount[i]);
  }*/
  fscanf(counterFile, "%d %d", &dataCount[0], &dataCount[1]);
  
  //printf("%d",dataCount[1]);

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
 

    //printf("\n\n=== Package Index %d ===\n", index);
    //printf("SENDER: %s\n", deliveredPackageData[index].sender);
    //printf("RECEIVER: %s\n", deliveredPackageData[index].reciever);
    //printf("ID: %s\n", deliveredPackageData[index].id);
    //printf("FROM: %d\n", FromProvinceID);
    //printf("TO: %d\n", ToProvinceID);
    //printf("TIMESTAMP: %s", ctime(&deliveredPackageData[index].time));
    //printf("DELIVERED TIMESTAMP: %s\n", ctime(&deliveredPackageData[index].deliveredTime));
    //printf("=== Package Index %d ===\n", index);



  fclose(ongoingPackageFile);
  
  end_time = clock();
  printf("runtime : %.2lf ms",(double)end_time - start_time);

  return;
}

void loadDeliveredPackageData(){
  start_time = clock();
  FILE *deliveredPackageFile = fopen(dataPath"DeliveredPackageData.txt", "r");
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
    }
    fclose(deliveredPackageFile);
    
}