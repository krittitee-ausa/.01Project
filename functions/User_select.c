void Admin_POV() // หน้าเมนูสำหรับผู้ดูแลระบบ
{
    int n;
    while (1)
    {
        printf("\n 1.List all ongoing package.\n 2.List all delivered package.\n 3.check a package status.\n 4.change a package status.\n 5.make (a) delivery order(s).\n 6.view summary.\n");
        printf("your desired service number (-1 to exit program): ");
        scanf("%d", &n);
        getchar();

        switch (n)
        {
        case -1: // ออกจากการทำงาน
            printf("goodbye.");
            return;
        case 1: // ดูรายการพัสดุที่กำลังจัดส่งทั้งหมด
            printf("\033[1mSure!\n Here's all the package that are in delivery process!\033[0m\n");
            loadOngoingdata(); // อยู่ใน ./functions/loadOngoingdata.c
            break;
        case 2: // ดูรายการพัสดุที่จัดส่งสำเร็จ
            printf("\033[1mSure!\n Here's all the package that already delivered!\033[0m\n");
            loadDelivereddata(); // อยู่ใน ./functions/loadOngoingdata.c
            break;
        case 3: // ตรวจสอบพัสดุ
            printf("\033[1mSure!\033[0m");
            checkStatus(); // อยู่ใน ./functions/ChangeandCheckStatus.c
            break;
        case 4: // เปลี่ยนสถานะการจัดส่ง
            printf("\033[1mSure!\033[0m");
            changeStatus(); // อยู่ใน ./functions/ChangeandCheckStatus.c
            break;
        case 5: // เพิ่มพัสดุเข้าระบบ
            printf("\033[1mSure!\033[0m");
            NewOrder(); // อยู่ใน ./functions/placeNewOrder.c
            break;
        case 6: // ดูสรุป
            printf("\033[1mSure!\033[0m");
            Summarize(); // อยู่ใน ./functions/Summarize.c
            break;
        default: // กรอกเมนูผิด
            printf("\033[1m Invalid command, please input the number of command again.\033[0m");
            break;
        }
    }
}

void Customer_POV() // หน้าเมนูสำหรับลูกค้า
{
    int n;
    while (1)
    {
        printf("\n1.check a package status.\n2.make (a) delivery order(s).\n");
        printf("your desired service number (-1 to exit program): ");
        scanf("%d", &n);
        getchar();
        switch (n)
        {
        case -1: // ปิดการทำงานของโปรแกรม
            printf("goodbye.");
            return;
        case 1: // ตรวจสอบพัสดุ
            printf("\033[1mSure!\033[0m");
            checkStatus();
            break;
        case 2: // เพิ่มข้อมูลเข้าระบบ
            printf("\033[1mSure!\033[0m");
            NewOrder();
            break;
        default: // กรอกตัวเลือกผิด
            printf("\033[1m Invalid command, please input the number of command again.\033[0m");
            break;
        }
    }
}