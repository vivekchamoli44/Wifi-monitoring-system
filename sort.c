void sort(){
    FILE *p;
    p=fopen("record.txt","r");
    if(p==NULL){
        printf("record.txt does not exist");
        return;
    }
    int c=0;
    struct WifiUsage n;
    while(fscanf(p,"%s %d %f %d %d",n.location,&n.users,&n.dataUsed,&n.m.month,&n.m.year)!=EOF){
        c++;
    }
    rewind(p);
    struct WifiUsage r[c];
    int i=0,j;
    while(fscanf(p,"%s %d %f %d %d",r[i].location,&r[i].users,&r[i].dataUsed,&r[i].m.month,&r[i].m.year)!=EOF){
        i++;
    }
    struct WifiUsage temp;
    for(i=0;i<=c-2;i++){
        for(j=i+1;j<=c-1;j++){
            if(r[i].dataUsed<r[j].dataUsed){
                temp=r[i];
                r[i]=r[j];
                r[j]=temp;
            }
        }
    }
    printf("\n-----SORTED LIST-----\n");
    for(i=0;i<c;i++){
        printf("\n---------------------------------------------\n");
        printf("Location: %s\n",r[i].location);
        printf("No of users: %d\n",r[i].users);
        printf("Dataused: %.2f\n",r[i].dataUsed);
        printf("Month and year:%d/%d",r[i].m.month,r[i].m.year);
        printf("\n----------------------------------------------\n");
    }
}
