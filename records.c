void addrecord(){
    struct WifiUsage r;
    FILE *p;
    p=fopen("record.txt","a");
    if(p==NULL){
        printf("File does not exist");
        return;
    }
    getchar();
    printf("\nEnter Location: ");
    fgets(r.location,50,stdin);
    r.location[strlen(r.location)-1]='\0';
    printf("Enter no of Users: ");
    scanf("%d", &r.users);
    printf("Enter Data Used (GB): ");
    scanf("%f", &r.dataUsed);
    printf("Enter the month and year: ");
    scanf("%d%d\n",&r.m.month,&r.m.year);
    fprintf(p, "%s %d %.2f %d %d\n", r.location, r.users, r.dataUsed,r.m.month,r.m.year);
    fclose(p);
    printf("----- Record Added! -----\n");
};
void displayrecord() {
    struct WifiUsage r;
    FILE *p = fopen("record.txt", "r");
    if(p ==NULL) {
        printf("No Records Found!\n");
        return;
    }
    int m, y;
    int found = 0;
    printf("Enter Month: ");
    scanf("%d", &m);
    printf("Enter Year: ");
    scanf("%d", &y);
    printf("\n--- Records for %d/%d ---\n", m, y);
    while(fscanf(p,"%s %d %f %d %d",
                 r.location,
                 &r.users,
                 &r.dataUsed,
                 &r.m.month,
                 &r.m.year) != EOF) {

        if(r.m.month==m && r.m.year==y) {
            printf("---------------------------------");
            printf("\nLocation: %s", r.location);
            printf("\nUsers: %d", r.users);
            printf("\nData Used: %.2f GB\n", r.dataUsed);
            found = 1;
            printf("--------------------------------\n");
        }
    }
    if(!found) {
        printf("No records found for this month & year.\n");
    }
    fclose(p);
}
void searchbylocation(){
    struct WifiUsage r;
    FILE *p;
    p=fopen("record.txt","r");
    char loc[50];
    int f=0;
    getchar();
    printf("Enter the location:");
    fgets(loc,50,stdin);
    loc[strlen(loc)-1]='\0';
    printf("\n----- Records for %s -----\n\n",loc);
    while(fscanf(p,"%s %d %f %d %d",
                 r.location,
                 &r.users,
                 &r.dataUsed,
                 &r.m.month,
                 &r.m.year)!=EOF){
                    if(strcmp(r.location,loc)==0){
                        f=1;
                        printf("Location: %s\n",r.location);
                        printf("No of users: %d\n",r.users);
                        printf("Dataused: %.2f\n",r.dataUsed);
                        printf("Month and year:%d/%d",r.m.month,r.m.year);
                        printf("\n\n");
                    }
                 }
                 if(!f){
                    printf("No Record found for this location\n");
                 }
                 fclose(p);
}