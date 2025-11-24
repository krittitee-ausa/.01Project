typedef struct{
    char name[50];
    int index;
    
}lowercaseP;
int provinceIndex[2];
lowercaseP* lowercaseProvinces; 
int lowercase(char str[],int* index){
    char str2[] = "see all provinces";
    if (strcmp(str,str2) == 0){
        for (int i = 0;i < ProvincesCount;i++){
            printf("%s\n",Provinces[i].provinceNameEn);
            
        }
        printf("\n please input the province again : ");
    }
    else{
        for (int i = 0;i < strlen(str);i++){
            if (str[i] <= 90 && str[i] >=65){
            str[i]+=32;
            }
        }
        for (int i = 0; i < ProvincesCount;i++){
            if (strcmp(str,lowercaseProvinces[i].name) == 0)
            { 
                *index = i;
                return 1;
            }
        }
        //printf("%s\n",buffer[2]);
        printf("invalid provinces, please input the provinces again (type \"see all provinces\" to view all province possible.)\n: ");
        
    }
    return 0;
    
}
void readlowercaseProvinces(){
    lowercaseProvinces = calloc(ProvincesCount,sizeof(lowercaseP));
    for (int i = 0; i < ProvincesCount;i++){
        strcpy(lowercaseProvinces[i].name,Provinces[i].provinceNameEn);
        lowercaseProvinces[i].index = Provinces[i].provinceCode;
        for (int j = 0;j < strlen(lowercaseProvinces[i].name);j++){
        if (lowercaseProvinces[i].name[j] <= 90 && lowercaseProvinces[i].name[j] >=65){
            lowercaseProvinces[i].name[j]+=32;
        }
    }
        }
    
    
    for (int i = 0; i < ProvincesCount;i++){
        printf("\n%d : %s",lowercaseProvinces[i].index,lowercaseProvinces[i].name);
    }
}

void NewOrder(){
    char buffer[4][50];
    printf("sure!, what's your name? : ");
    fgets(buffer[0],50,stdin);
    buffer[0][strlen(buffer[0])-1] = '\0';

    printf("who do you want to send yor package to? : ");
    fgets(buffer[1],50,stdin);
    buffer[1][strlen(buffer[1])-1] = '\0';

    
    printf("what province are you in? (type \"see all provinces\" to view all province possible.)\n: ");
    fgets(buffer[2],50,stdin);
    buffer[2][strlen(buffer[2])-1] = '\0';
    while (lowercase(buffer[2],&provinceIndex[0]) == 0){
        fgets(buffer[2],50,stdin);
        buffer[2][strlen(buffer[2])-1] = '\0';
    }
    

    
    printf("and what is the destination's province? (type \"see all provinces\" to view all province possible.)\n ");
    fgets(buffer[3],50,stdin);
    buffer[3][strlen(buffer[3])-1] = '\0';
    while (lowercase(buffer[3],&provinceIndex[1]) == 0){
        fgets(buffer[3],50,stdin);
        buffer[3][strlen(buffer[3])-1] = '\0';
    }
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
            package* temp = realloc(onGoingPackageData,dataCount[0]*sizeof(package));
            onGoingPackageData = temp;
            strcpy(onGoingPackageData[dataCount[0]-1].sender,buffer[0]);
            strcpy(onGoingPackageData[dataCount[0]-1].reciever,buffer[1]);
            onGoingPackageData[dataCount[0]-1].from = Provinces[provinceIndex[0]];
            onGoingPackageData[dataCount[0]-1].to = Provinces[provinceIndex[1]];
            char strbuffer[11];
            char strbuffer2[13];
            sprintf(strbuffer2,"%d%d",onGoingPackageData[dataCount[0]-1].from.provinceCode,onGoingPackageData[dataCount[0]-1].to.provinceCode);
            time_t rawtime;
            sprintf(strbuffer,"%lld",time(&rawtime));
            strcat(strbuffer2,&strbuffer[4]);
            long long tmp[4];
            char *end;
            tmp[0] = strtoll(strbuffer2,&end,10);
            while(1){
                int a = 0;
                for (int i = 0; i < dataCount[0]+dataCount[1];i++){
                    if (i < dataCount[0]){
                        tmp[1] = strtoll(onGoingPackageData[i].id,&end,10);
                        if (tmp[1] == tmp[0]){
                            tmp[0]++;
                            a = 1;
                            break;
                        }
                        
                    }
                    else if (i >= dataCount[0] && i < dataCount[0]+dataCount[1]){
                         tmp[1] = strtoll(deliveredPackageData[i-dataCount[0]].id,&end,10);
                        if (tmp[1] == tmp[0]){
                            tmp[0]++;
                            a = 1;
                            break;
                        }
                    }
                    else a = 0;
                }
                if (a == 0) break;

            }
            sprintf(strbuffer2,"%lld",tmp[0]);
            strcpy(onGoingPackageData[dataCount[0]-1].id,strbuffer2);
            onGoingPackageData[dataCount[0]-1].time = time(&rawtime);

            
            return;
        }
        else if(ans == 'n'){
            int index;
            while(1){
                printf("Which data do you want to edit?\n1. Sender name\n2. Reciever name\n3. your province\n4. destination's province\nYour function : ");
                scanf("%d",&index);
                getchar();
                if (index < 1 || index > 4){
                    printf("please input the valid function number\n");
                    continue;
                }
                break;
            }
            printf("sure!\nplease input a new data : ");
            fgets(buffer[index-1],50,stdin);
            buffer[index-1][strlen(buffer[index-1])-1] = '\0';
            if (index >= 3){
                while(lowercase(buffer[index-1],&provinceIndex[index -3]) == 0){
                    fgets(buffer[index-1],50,stdin);
                    buffer[index-1][strlen(buffer[index-1])-1] = '\0';
                }
            }
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