#include <stdio.h>
#include <stdlib.h>

int main() {
    int choice;

    do {
        printf("\n=== Logistics Management System ===\n\n");
        printf("1) City Management\n");
        printf("2) Distance Management\n");
        printf("3) Vehicle Management\n");
        printf("4) Delivery Management\n");
        printf("5) Reports\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("City Management selected (not added yet)\n");
                break;
            case 2:
                printf("Distance Management selected (not added yet)\n");
                break;
            case 3:
                printf("Vehicle Management selected (not added yet)\n");
                break;
            case 4:
                printf("Delivery Management selected (not added yet)\n");
                break;
            case 5:
                printf("Reports selected (not added yet)\n");
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid..Please Try again!\n");
        }
    } while (choice != 6);

    return 0;
}
