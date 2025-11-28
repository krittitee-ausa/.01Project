void Admin_POV()
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
        case -1:
            printf("goodbye.");
            return;
        case 1:
            printf("\033[1mSure!\n Here's all the package that are in delivery process!\033[0m\n");
            loadOngoingdata();
            break;
        case 2:
            printf("\033[1mSure!\n Here's all the package that already delivered!\033[0m\n");
            loadDelivereddata();
            break;
        case 3:
            printf("\033[1mSure!\033[0m");
            checkStatus();
            break;
        case 4:
            printf("\033[1mSure!\033[0m");
            changeStatus();
            break;
        case 5:
            printf("\033[1mSure!\033[0m");
            NewOrder();
            break;
        case 6:
            printf("\033[1mSure!\033[0m");
            Summarize();
            break;
        default:
            printf("\033[1m Invalid command, please input the number of command again.\033[0m");
            break;
        }
    }
}

void Customer_POV()
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
        case -1:
            printf("goodbye.");
            return;
        case 1:
            printf("\033[1mSure!\033[0m");
            checkStatus();
            break;
        case 2:
            printf("\033[1mSure!\033[0m");
            NewOrder();
            break;
        default:
            printf("\033[1m Invalid command, please input the number of command again.\033[0m");
            break;
        }
    }
}