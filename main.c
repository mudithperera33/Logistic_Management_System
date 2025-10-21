#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define NAME_LENGTH 50

void cityMenu(char cities[MAX_CITIES][NAME_LENGTH], int *cityCount);
void addCity(char cities[MAX_CITIES][NAME_LENGTH], int *cityCount);
void listCities(char cities[MAX_CITIES][NAME_LENGTH], int cityCount);

int main()
{
    char cities[MAX_CITIES][NAME_LENGTH];
    int cityCount = 0;
    int choice;

    do
    {
        printf("\n=== Logistics Management System ===\n\n");
        printf("1) City Management\n");
        printf("2) Distance Management\n");
        printf("3) Vehicle Management\n");
        printf("4) Delivery Management\n");
        printf("5) Reports\n");
        printf("6) Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            cityMenu(cities, &cityCount);
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
    }
    while (choice != 6);

    return 0;
}


void cityMenu(char cities[MAX_CITIES][NAME_LENGTH], int *cityCount)
{
    int choice;

    do
    {
        printf("\n=== City Management ===\n");
        printf("1) Add City\n");
        printf("2) List Cities\n");
        printf("3) Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addCity(cities, cityCount);
            break;
        case 2:
            listCities(cities, *cityCount);
            break;
        case 3:
            break;
        default:
            printf("Invalid..Please Try again.\n");
        }
    }
    while (choice != 0);
}

void addCity(char cities[MAX_CITIES][NAME_LENGTH], int *cityCount)
{
    if (*cityCount >= MAX_CITIES)
    {
        printf("Limit reached! Cannot add more cities\n");
        return;
    }

    printf("Enter city name: ");
    fgets(cities[*cityCount], NAME_LENGTH, stdin);

    cities[*cityCount][strcspn(cities[*cityCount], "\n")] = '\0';

    printf("City added successfully!\n");
    (*cityCount)++;
}

void listCities(char cities[MAX_CITIES][NAME_LENGTH], int cityCount)
{
    printf("\n--- List of Cities ---\n");

    if (cityCount == 0)
    {
        printf("No cities added yet.\n");
        return;
    }

    for (int i = 0; i < cityCount; i++)
    {
        printf("%d. %s\n", i + 1, cities[i]);
    }
}
