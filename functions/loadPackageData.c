package *onGoingPackageData;
package *deliveredPackageData;
int dataCount[3];
#include <stdio.h>
#include <time.h>

double time_spent;

int compareTime(const void *a, const void *b) // เปรียบเทียบเวลา ใช้สำหรับการจำเรียงลำดับข้อมูล
{
  const package *A = (const package *)a;
  const package *B = (const package *)b;

  if (A->time < B->time)
  {
    return -1;
  }
  else if (A->time > B->time)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

void loadPackageData() // อ่านค่าพัสดุทั้งหมดที่กำลังจัดส่งจากไฟล์
{
  FILE *counterFile = fopen(dataPath "counter.txt", "r"); // เปิดไฟล์
  FILE *ongoingPackageFile = fopen(dataPath "onGoingPackage.txt", "r"); // เปิดไฟล์

  fscanf(counterFile, "%d %d", &dataCount[0], &dataCount[1]); // อ่านค่าจำนวนของพัสดุในไฟล์
  dataCount[2] = dataCount[1];

  onGoingPackageData = calloc(dataCount[0], sizeof(package)); // จอง memory
  deliveredPackageData = calloc(dataCount[1], sizeof(package)); // จอง memory

  for (int index = 0; index < dataCount[0]; index++) // วนซ้ำตามจำนวนพัสดุที่กำลังจัดส่ง
  {
    int FromProvinceID;
    int ToProvinceID;
    // อ่านค่าแต่ละบรรทัด
    fscanf(ongoingPackageFile, " %[^\n]\n", onGoingPackageData[index].sender);
    fscanf(ongoingPackageFile, " %[^\n]\n", onGoingPackageData[index].reciever);
    fscanf(ongoingPackageFile, "%s", onGoingPackageData[index].id);
    fscanf(ongoingPackageFile, "%d", &FromProvinceID);
    fscanf(ongoingPackageFile, "%d", &ToProvinceID);
    fscanf(ongoingPackageFile, "%ld", &onGoingPackageData[index].time);

    for (int i = 0; i < ProvincesCount; i++) // วนซ้ำตามจำนวนจังหวัด เพื่อหาจังหวัดที่มี Code ตรงกับที่เก็บไว้ในไฟล์ และนำไปเก็ยใน onGoingPackageData
    {
      if (FromProvinceID == Provinces[i].provinceCode)
      {
        onGoingPackageData[index].from = Provinces[i];
      }
      if (ToProvinceID == Provinces[i].provinceCode)
      {
        onGoingPackageData[index].to = Provinces[i];
      }
    }

  }

  fclose(ongoingPackageFile); // ปิดไฟล์

  qsort(onGoingPackageData, dataCount[0], sizeof(package), compareTime); // เรียงลำดับข้อมูลตามเวลาจากน้อยไปมาก

  return;
}

void loadDeliveredPackageData() // อ่านค่าพัสดุทั้งหมดที่จัดส่งสำเร็จจากไฟล์
{

  FILE *deliveredPackageFile = fopen(dataPath "DeliveredPackageData.txt", "r"); // เปิดไฟล์
  for (int index = 0; index < dataCount[1]; index++) // วนซำ้ตามจำนวนพัสดุที่จัดส่งสำเร็จ
  {
    int FromProvinceID;
    int ToProvinceID;
    // อ่านค่าแต่ละบรรทัด
    fscanf(deliveredPackageFile, " %[^\n]\n", deliveredPackageData[index].sender);
    fscanf(deliveredPackageFile, " %[^\n]\n", deliveredPackageData[index].reciever);
    fscanf(deliveredPackageFile, "%s", deliveredPackageData[index].id);
    fscanf(deliveredPackageFile, "%d", &FromProvinceID);
    fscanf(deliveredPackageFile, "%d", &ToProvinceID);
    fscanf(deliveredPackageFile, "%ld", &deliveredPackageData[index].time);
    fscanf(deliveredPackageFile, "%ld", &deliveredPackageData[index].deliveredTime);

    for (int i = 0; i < ProvincesCount; i++) // วนซ้ำเพื่อหาจังหวัดที่ Code ตรงกับที่เก็บไว้
    {
      if (FromProvinceID == Provinces[i].provinceCode)
      {
        deliveredPackageData[index].from = Provinces[i];
      }
      if (ToProvinceID == Provinces[i].provinceCode)
      {
        deliveredPackageData[index].to = Provinces[i];
      }
    }
  }
  fclose(deliveredPackageFile); // ปิดไฟล์

  qsort(deliveredPackageData, dataCount[1], sizeof(package), compareTime); // เรียงลำดับข้อมูลตามเวลาจากน้อยไปมาก
}