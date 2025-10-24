#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CITIES 30
#define NAME_LENGTH 50

void cityMenu(char cities[MAX_CITIES][NAME_LENGTH], int *cityCount);
void addCity(char cities[MAX_CITIES][NAME_LENGTH], int *cityCount);
void listCities(char cities[MAX_CITIES][NAME_LENGTH], int cityCount);
void removeCity(char cities[MAX_CITIES][NAME_LENGTH], int *cityCount);
void renameCity(char cities[MAX_CITIES][NAME_LENGTH], int cityCount);
void distanceMenu(int distance[MAX_CITIES][MAX_CITIES], int cityCount, char cities[MAX_CITIES][NAME_LENGTH]);
void editDistance(int distance[MAX_CITIES][MAX_CITIES], int cityCount, char cities[MAX_CITIES][NAME_LENGTH]);
void viewDistances(int distance[MAX_CITIES][MAX_CITIES], int cityCount, char cities[MAX_CITIES][NAME_LENGTH]);


int main()
{
    char cities[MAX_CITIES][NAME_LENGTH];
    int distance[MAX_CITIES][MAX_CITIES] = {0};
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
            distanceMenu(distance, cityCount, cities);
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
        printf("3) Remove City\n");
        printf("4) Rename City\n");
        printf("5) Back to main menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addCity(cities, cityCount);
            break;
        case 2:
            listCities(cities,*cityCount);
            break;
        case 3:
            removeCity(cities,cityCount);
            break;
        case 4:
            renameCity(cities,*cityCount);
            break;
        case 5:
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
void removeCity(char cities[MAX_CITIES][NAME_LENGTH], int *cityCount)
{
    if (*cityCount == 0)
    {
        printf("No cities to remove.\n");
        return;
    }

    listCities(cities, *cityCount);

    int index;
    printf("Enter the number of the city to remove: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > *cityCount)
    {
        printf("Invalid city number.\n");
        return;
    }

    for (int i = index - 1; i < *cityCount - 1; i++)
    {
        strcpy(cities[i], cities[i + 1]);
    }

    (*cityCount)--;

    printf("City removed successfully!\n");

}

void renameCity(char cities[MAX_CITIES][NAME_LENGTH], int cityCount)
{
    if (cityCount == 0)
    {
        printf("No cities to rename.\n");
        return;
    }

    listCities(cities, cityCount);

    int index;
    printf("Enter the number of the city to rename: ");
    scanf("%d", &index);
    getchar();

    if (index < 1 || index > cityCount)
    {
        printf("Invalid city number.\n");
        return;
    }

    printf("Enter the new name for city '%s': ", cities[index - 1]);
    fgets(cities[index - 1], NAME_LENGTH, stdin);
    cities[index - 1][strcspn(cities[index - 1], "\n")] = '\0';

    printf("City renamed successfully!\n");
}


void distanceMenu(int distance[MAX_CITIES][MAX_CITIES], int cityCount, char cities[MAX_CITIES][NAME_LENGTH])
{
    int choice;

    do
    {
        printf("\n=== Distance Management ===\n");
        printf("1) Add / Edit Distance\n");
        printf("2) View All Distances\n");
        printf("0) Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            editDistance(distance, cityCount, cities);
            break;
        case 2:
            viewDistances(distance, cityCount, cities);
            break;
        case 0:
            printf("Returning to Main Menu...\n");
            break;
        default:
            printf("Invalid choice! Try again.\n");
        }

    }
    while (choice != 0);
}

void editDistance(int distance[MAX_CITIES][MAX_CITIES], int cityCount, char cities[MAX_CITIES][NAME_LENGTH])
{
    if (cityCount < 2)
    {
        printf("Add at least two cities first!\n");
        return;
    }

    printf("\n--- Edit Distance Between Cities ---\n");
    for (int i = 0; i < cityCount; i++)
    {
        printf("%d. %s\n", i + 1, cities[i]);
    }

    int city1, city2, dist;

    printf("Enter number of first city: ");
    scanf("%d", &city1);
    printf("Enter number of second city: ");
    scanf("%d", &city2);
    printf("Enter distance in km: ");
    scanf("%d", &dist);
    getchar();

    if (city1 < 1 || city1 > cityCount || city2 < 1 || city2 > cityCount)
    {
        printf("Invalid city number!\n");
        return;
    }

    if (city1 == city2)
    {
        printf("Distance from a city to itself is 0.\n");
        distance[city1 - 1][city2 - 1] = 0;
        return;
    }

    distance[city1 - 1][city2 - 1] = dist;
    distance[city2 - 1][city1 - 1] = dist;

    printf("Distance updated successfully!\n");
}

void viewDistances(int distance[MAX_CITIES][MAX_CITIES], int cityCount, char cities[MAX_CITIES][NAME_LENGTH])
{
    if (cityCount < 2)
    {
        printf("Add at least two cities first!\n");
        return;
    }

    printf("\n--- Distance Table ---\n    ");
    for (int i = 0; i < cityCount; i++)
    {
        printf("%s ", cities[i]);
    }
    printf("\n");

    for (int i = 0; i < cityCount; i++)
    {
        printf("%s ", cities[i]);
        for (int j = 0; j < cityCount; j++)
        {
            printf("%10d ", distance[i][j]);
        }
        printf("\n");
    }
}
