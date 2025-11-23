void NewOrder(){
    char buffer[4][150];
    printf("sure!, what's your name? : ");
    scanf("%s",buffer[0]);
    printf("who do you want to send yor package to? : ");
    scanf("%s",buffer[1]);
    printf("what province are you in? : ");
    scanf("%s",buffer[2]);
    printf("and what is the destination's province? : ");
    scanf("%s",buffer[3]);
    char ans;
    while(1){
        printf("\nSENDER : %s \n",buffer[0]);
        printf("RECIEVER : %s \n",buffer[1]);
        printf("FROM : %s \n",buffer[2]);
        printf("TO : %s \n",buffer[3]);
        printf("\nis the information correct?(y/n and c to cancel) : ");
        scanf("%c",&ans);
        getchar();
        if (ans == 'y'){
            printf("\033[1m\nSuccess! You successfully placed an order!\n\033[0m");
            dataCount[0]++;
            
            package* temp = realloc(onGoingPackagedata,dataCount[0]*sizeof(package));
            return;
        }
        else if(ans == 'n'){
            int index;
            printf("Which data do you want to edit?\n1. Sender name\n2. Reciever name\n3. your province\n4. destination's province");
            scnaf("%d",&index);
            getchar();
            printf("sure!\nplease input a new data : ");
            scanf("%s", buffer[index-1]);
            printf("\n");
            
        }
        else if(ans == 'c'){
            printf("cancelling the order.\n Success!\n");
            return;
        }
        else {
            printf("please input the mentioned characters.\n");
        }
    }
    
    

}