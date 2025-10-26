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
void vehicleMenu();
void deliveryMenu(char cities[MAX_CITIES][NAME_LENGTH], int cityCount,
                  int distance[MAX_CITIES][MAX_CITIES],
                  char fromCity[30][NAME_LENGTH], char toCity[30][NAME_LENGTH],
                  char vehicleType[30][20], float packageWeight[30], int *deliveryCount);
void addDelivery(char cities[MAX_CITIES][NAME_LENGTH], int cityCount,
                 char fromCity[30][NAME_LENGTH], char toCity[30][NAME_LENGTH],
                 char vehicleType[30][20], float packageWeight[30], int *deliveryCount);
void viewDeliveries(char fromCity[30][NAME_LENGTH], char toCity[30][NAME_LENGTH],
                    char vehicleType[30][20], float packageWeight[30], int deliveryCount);
void reportsMenu(char fromCity[30][NAME_LENGTH], char toCity[30][NAME_LENGTH],
                 char vehicleType[30][20], float packageWeight[30], int deliveryCount,
                 char cities[MAX_CITIES][NAME_LENGTH], int distance[MAX_CITIES][MAX_CITIES], int cityCount);
void loadCities(char cities[MAX_CITIES][NAME_LENGTH], int *cityCount);
void saveCities(char cities[MAX_CITIES][NAME_LENGTH], int cityCount);


int main()
{

    char cities[MAX_CITIES][NAME_LENGTH];
    int distance[MAX_CITIES][MAX_CITIES] = {0};
    int cityCount = 0;
    int choice;
    char fromCity[30][NAME_LENGTH];
    char toCity[30][NAME_LENGTH];
    char vehicleType[30][20];
    float packageWeight[30];
    int deliveryCount = 0;
    loadCities(cities, &cityCount);

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
            vehicleMenu();
            break;
        case 4:
            deliveryMenu(cities, cityCount, distance, fromCity, toCity, vehicleType, packageWeight, &deliveryCount);
            break;
        case 5:
            reportsMenu(fromCity, toCity, vehicleType, packageWeight, deliveryCount, cities, distance, cityCount);
            break;
        case 6:
            saveCities(cities, cityCount);
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
            listCities(cities, *cityCount);
            break;
        case 3:
            removeCity(cities, cityCount);
            break;
        case 4:
            renameCity(cities, *cityCount);
            break;
        case 5:
            break;
        default:
            printf("Invalid..Please Try again.\n");
        }
    }
    while (choice != 5);
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
        printf("%10s ", cities[i]);
    }
    printf("\n");

    for (int i = 0; i < cityCount; i++)
    {
        printf("%10s ", cities[i]);
        for (int j = 0; j < cityCount; j++)
        {
            printf("%10d ", distance[i][j]);
        }
        printf("\n");
    }
}

void vehicleMenu()
{
    int choice;
    char vehicleNames[3][20] = {"Van", "Truck", "Lorry"};
    int capacity[3] = {1000, 5000, 10000};
    int ratePerKm[3] = {30, 40, 80};
    int avgSpeed[3] = {60, 50, 45};
    int fuelEfficiency[3] = {12, 6, 4};

    do
    {
        printf("\n=== Vehicle Management ===\n");
        printf("1) View Vehicle Details\n");
        printf("2) Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1)
        {
            printf("\n--- Vehicle Details ---\n");
            printf("Type\tCapacity(kg)\tRate/km(LKR)\tAvgSpeed(km/h)\tFuelEff(km/l)\n");
            printf("-------------------------------------------------------------------\n");

            for (int i = 0; i < 3; i++)
            {
                printf("%s\t%d\t\t%d\t\t%d\t\t%d\n",
                       vehicleNames[i],
                       capacity[i],
                       ratePerKm[i],
                       avgSpeed[i],
                       fuelEfficiency[i]);
            }

            printf("-------------------------------------------------------------------\n");
        }
        else if (choice == 2)
        {
            printf("Returning to Main Menu...\n");
        }
        else
        {
            printf("Invalid choice! Please try again.\n");
        }
    }
    while (choice != 2);
}

void deliveryMenu(char cities[MAX_CITIES][NAME_LENGTH], int cityCount,
                  int distance[MAX_CITIES][MAX_CITIES],
                  char fromCity[30][NAME_LENGTH], char toCity[30][NAME_LENGTH],
                  char vehicleType[30][20], float packageWeight[30], int *deliveryCount)
{
    int choice;
    do
    {
        printf("\n=== Delivery Management ===\n");
        printf("1) Add Delivery\n");
        printf("2) View Deliveries\n");
        printf("3) View Reports\n");
        printf("4) Back to Main Menu\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice)
        {
        case 1:
            addDelivery(cities, cityCount, fromCity, toCity, vehicleType, packageWeight, deliveryCount);
            break;

        case 2:
            viewDeliveries(fromCity, toCity, vehicleType, packageWeight, *deliveryCount);
            break;

        case 3:
            reportsMenu(fromCity, toCity, vehicleType, packageWeight, *deliveryCount, cities, distance, cityCount);
            break;

        case 4:
            printf("Returning to Main Menu...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }


    }
    while (choice != 4);
}

void addDelivery(char cities[MAX_CITIES][NAME_LENGTH], int cityCount,
                 char fromCity[30][NAME_LENGTH], char toCity[30][NAME_LENGTH],
                 char vehicleType[30][20], float packageWeight[30], int *deliveryCount)
{
    if (cityCount < 2)
    {
        printf("Please add at least two cities before adding deliveries.\n");
        return;
    }

    if (*deliveryCount >= 30)
    {
        printf("Cannot add more deliveries. Limit reached.\n");
        return;
    }

    printf("\n--- Add New Delivery ---\n");

    printf("Available cities:\n");
    for (int i = 0; i < cityCount; i++)
    {
        printf("%d) %s\n", i + 1, cities[i]);
    }

    int from, to;
    printf("Enter the number of the source city: ");
    scanf("%d", &from);
    getchar();
    printf("Enter the number of the destination city: ");
    scanf("%d", &to);
    getchar();

    if (from < 1 || to < 1 || from > cityCount || to > cityCount || from == to)
    {
        printf("Invalid city selection.\n");
        return;
    }

    int vChoice;
    printf("\nSelect vehicle type:\n");
    printf("1) Van\n2) Truck\n3) Lorry\n");
    scanf("%d", &vChoice);
    getchar();

    switch (vChoice)
    {
    case 1:
        strcpy(vehicleType[*deliveryCount], "Van");
        break;
    case 2:
        strcpy(vehicleType[*deliveryCount], "Truck");
        break;
    case 3:
        strcpy(vehicleType[*deliveryCount], "Lorry");
        break;
    default:
        printf("Invalid vehicle type.\n");
        return;
    }

    printf("Enter package weight (kg): ");
    scanf("%f", &packageWeight[*deliveryCount]);
    getchar();

    strcpy(fromCity[*deliveryCount], cities[from - 1]);
    strcpy(toCity[*deliveryCount], cities[to - 1]);

    printf("Delivery added successfully!\n");
    (*deliveryCount)++;
}

void viewDeliveries(char fromCity[30][NAME_LENGTH], char toCity[30][NAME_LENGTH],
                    char vehicleType[30][20], float packageWeight[30], int deliveryCount)
{
    if (deliveryCount == 0)
    {
        printf("No deliveries added yet.\n");
        return;
    }

    for (int i = 0; i < deliveryCount; i++)
    {
        int distance = 100 + (i * 25);
        int rate, speed, efficiency;

        if (strcmp(vehicleType[i], "Van") == 0)
        {
            rate = 30;
            speed = 60;
            efficiency = 12;
        }
        else if (strcmp(vehicleType[i], "Truck") == 0)
        {
            rate = 40;
            speed = 50;
            efficiency = 6;
        }
        else
        {
            rate = 80;
            speed = 45;
            efficiency = 4;
        }

        float cost = rate * distance;
        float time = (float)distance / speed;
        float fuelUsed = (float)distance / efficiency;

        printf("\nDelivery %d:\n", i + 1);
        printf("From: %s\nTo: %s\nVehicle: %s\nWeight: %.1f kg\n",
               fromCity[i], toCity[i], vehicleType[i], packageWeight[i]);
        printf("Distance: %d km | Cost: Rs. %.2f | Time: %.2f hrs | Fuel Used: %.2f L\n",
               distance, cost, time, fuelUsed);
    }
}

void reportsMenu(char fromCity[30][NAME_LENGTH], char toCity[30][NAME_LENGTH],
                 char vehicleType[30][20], float packageWeight[30], int deliveryCount,
                 char cities[MAX_CITIES][NAME_LENGTH], int distance[MAX_CITIES][MAX_CITIES], int cityCount)
{
    if (deliveryCount == 0)
    {
        printf("No deliveries available to report.\n");
        return;
    }

    float totalCost = 0;
    int totalDeliveries = deliveryCount;

    for (int i = 0; i < deliveryCount; i++)
    {
        int fromIndex = -1, toIndex = -1;
        for (int j = 0; j < cityCount; j++)
        {
            if (strcmp(fromCity[i], cities[j]) == 0) fromIndex = j;
            if (strcmp(toCity[i], cities[j]) == 0) toIndex = j;
        }

        if (fromIndex == -1 || toIndex == -1)
        {
            printf("Error: City not found for delivery %d\n", i + 1);
            continue;
        }

        int dist = distance[fromIndex][toIndex];
        int rate, speed, efficiency;

        if (strcmp(vehicleType[i], "Van") == 0)
        {
            rate = 30;
            speed = 60;
            efficiency = 12;
        }
        else if (strcmp(vehicleType[i], "Truck") == 0)
        {
            rate = 40;
            speed = 50;
            efficiency = 6;
        }
        else
        {
            rate = 80;
            speed = 45;
            efficiency = 4;
        }

        float cost = rate * dist;
        totalCost += cost;
    }

    float avgCost = totalCost / totalDeliveries;

    printf("\n=== Reports Summary ===\n");
    printf("Total Deliveries: %d\n", totalDeliveries);
    printf("Total Cost of All Deliveries: Rs. %.2f\n", totalCost);
    printf("Average Cost per Delivery: Rs. %.2f\n", avgCost);
}
void loadCities(char cities[MAX_CITIES][NAME_LENGTH], int *cityCount)
{
    FILE *file = fopen("cities.txt", "r");
    if (file == NULL)
    {
        printf("No saved city data found. Starting fresh.\n");
        return;
    }

    *cityCount = 0;
    while (fgets(cities[*cityCount], NAME_LENGTH, file) != NULL)
    {
        cities[*cityCount][strcspn(cities[*cityCount], "\n")] = '\0';
        (*cityCount)++;

        if (*cityCount >= MAX_CITIES)
            break;
    }

    fclose(file);
    printf("Loaded %d cities from file.\n", *cityCount);
}

void saveCities(char cities[MAX_CITIES][NAME_LENGTH], int cityCount)
{
    FILE *file = fopen("cities.txt", "w");
    if (file == NULL)
    {
        printf("Error saving city data!\n");
        return;
    }

    for (int i = 0; i < cityCount; i++)
    {
        fprintf(file, "%s\n", cities[i]);
    }

    fclose(file);
    printf("City data saved successfully!\n");
}
