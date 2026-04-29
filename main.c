struct month{
    int month;
    int year;
};
struct WifiUsage {
    char location[50];
    int users;
    float dataUsed;
    struct month m;
};
#include<stdio.h>
#include<string.h>
#include"auth.c"
#include"records.c"
#include "analysis.c"
#include "sort.c"
int main() {
    int count = 0, choice;
    if(!loginuser()) {
        printf("Access Denied!\n");
        return 0;
    }
    do {
        printf("\n----- GEU Wi-Fi Monitoring System -----\n\n");
        printf("---MENU---\n");
        printf("1. Add Record\n");
        printf("2. Display Records\n");
        printf("3. Analyze Usage\n");
        printf("4. Search By Location\n");
        printf("5. Display Sorted List\n");
        printf("6. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                addrecord();
                break;
            case 2:
                displayrecord();
                break;
            case 3:
                analyzeusage();
                break;
            break;
            case 4:
                searchbylocation();
                break;
            case 5:
                sort();
                break;
            case 6:
                printf("Data Saved. Exiting...\n");
                break;
            default:
                printf("Invalid choice!\n");
        }

    } while(choice != 6);

    return 0;
}