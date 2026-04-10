#include <stdio.h>
#include <string.h>

int loginuser(){
    char username[50],password[50];
    char fileuser[50],filepass[50];
    int c=0;
    FILE *p;
    printf("----- Login to GEU Wi-Fi Monitoring System -----\n");
    printf("Enter the username:");
    fgets(username,50,stdin);
    printf("Enter the password:");
    fgets(password,50,stdin);
    username[strlen(username)-1]='\0';
    password[strlen(password)-1]='\0';
    p=fopen("user.txt","r");  
    if(p == '\0') {             
        printf("Error opening file!\n");
        return 0;
    }
    while(fscanf(p,"%s%s",fileuser,filepass)!=EOF){
        if (strcmp(username,fileuser) == 0 &&strcmp(password,filepass) == 0){
           c=1;
           break;  
        }
    }
    fclose(p);  
    if(c==1){
        printf("Login successfull");
        return 1;
    }
    else{
        printf("Invalid Credentials!\n");
        return 0;  
    }
}