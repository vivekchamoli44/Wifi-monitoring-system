void analyzeusage(){
    struct WifiUsage r;
    FILE *p;
    p=fopen("record.txt","r");
    if(p==NULL){
        printf("File does not exist");
        return;
    }
    int max=0,min,i=0,mi=0,ma=0;
    if(fscanf(p,"%s %d %f %d %d",
                 r.location,
                 &r.users,
                 &r.dataUsed,
                 &r.m.month,
                &r.m.year)){
                    max=min=r.dataUsed;
                };
                rewind(p);
    while(fscanf(p,"%s %d %f %d %d",
                 r.location,
                 &r.users,
                 &r.dataUsed,
                 &r.m.month,
                 &r.m.year)!=EOF){
                    if(max<r.dataUsed){
                        max=r.dataUsed;
                        ma=i;
                    }
                    if(min>r.dataUsed){
                        min=r.dataUsed;
                        mi=i;
                    }
                    i++;
                 }
                 rewind(p);
                 i=0;
                 while(fscanf(p,"%s %d %f %d %d",
                 r.location,
                 &r.users,
                 &r.dataUsed,
                 &r.m.month,
                 &r.m.year)!=EOF){
                    if(i==ma){
                        printf("\n----- Max Usage Location Records -----\n");
                        printf("Location: %s\n",r.location);
                        printf("No of users: %d\n",r.users);
                        printf("Dataused: %.2f\n",r.dataUsed);
                        printf("Month and year:%d/%d\n",r.m.month,r.m.year);
                    }
                    if(i==mi){
                        printf("\n----- Minimum Usage Location Records -----\n");
                        printf("Location: %s\n",r.location);
                        printf("No of users: %d\n",r.users);
                        printf("Dataused: %.2f\n",r.dataUsed);
                        printf("Month and year:%d/%d\n",r.m.month,r.m.year);
                    }
                 }
}