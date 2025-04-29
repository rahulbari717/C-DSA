/************************************************************
 * Program: Travel Agency Driver Management System
 * Purpose: Collect and display driver details using structures
 * Author: Rahul Bari
 * Version: 2.0
 ************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/***************** Preprocessor Directives *****************/

// Define maximum sizes for strings
#define NAME_SIZE (50)
#define LICENSE_NO_SIZE (20)
#define ROUTE_SIZE (100)

// Define table width for drawing lines
#define TABLE_WIDTH (88)

/********************* Structure Definition ****************/

typedef struct
{
    char name[NAME_SIZE];
    char license_no[LICENSE_NO_SIZE];
    char route[ROUTE_SIZE];
    float kms;
} Driver;

/******************** Function Prototypes ******************/

int getDriverCount();
Driver *allocateMemory(int n);
void inputDriverDetails(Driver *driver, int driverNumber);
void getAllDriverDetails(Driver *drivers, int n);
void drawLine(int width);
void displayHeader();
void displayDriver(Driver driver, int index);
void displayFooter();
void displayDriverDetails(Driver *drivers, int n);
void freeMemory(Driver *drivers);

/********************* Function Definitions ****************/

/**
 * @brief Get the number of drivers from the user with input validation.
 */
int getDriverCount()
{
    int n;
    do
    {
        printf("Enter the number of drivers (must be > 0): ");
        scanf("%d", &n);
        if (n <= 0)
        {
            printf("❌ Invalid number of drivers. Please try again.\n");
        }
    } while (n <= 0);
    return n;
}

/**
 * @brief Allocate memory for drivers dynamically.
 */
Driver *allocateMemory(int n)
{
    Driver *drivers = (Driver *)malloc(n * sizeof(Driver));

    if (drivers == NULL)
    {
        printf("❌ Memory allocation failed. Exiting program.\n");
        exit(1);
    }

    return drivers;
}

/**
 * @brief Input a single driver's details.
 */
void inputDriverDetails(Driver *driver, int driverNumber)
{
    printf("\nEntering details for Driver #%d\n", driverNumber);
    drawLine(TABLE_WIDTH);

    printf("Name: ");
    scanf(" %[^\n]s", driver->name);

    printf("Driving License No: ");
    scanf(" %[^\n]s", driver->license_no);

    printf("Route: ");
    scanf(" %[^\n]s", driver->route);

    printf("Distance (in Kms): ");
    scanf("%f", &driver->kms);
}

/**
 * @brief Input all driver details.
 */
void getAllDriverDetails(Driver *drivers, int n)
{
    for (int i = 0; i < n; i++)
    {
        inputDriverDetails(&drivers[i], i + 1);
    }
}

/**
 * @brief Draw a horizontal line for better readability.
 */
void drawLine(int width)
{
    printf("+");
    for (int i = 0; i < width; i++)
    {
        printf("-");
    }
    printf("+\n");
}

/**
 * @brief Display the header of the driver details table.
 */
void displayHeader()
{
    printf("\n\n");
    printf("╔════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        TRAVEL AGENCY DRIVER DETAILS                                ║\n");
    printf("╠════════╦══════════════════════════╦════════════════════╦══════════════════════╦═══════════╣\n");
    printf("║  No.   ║          Name            ║    License No.     ║        Route         ║    Kms    ║\n");
    printf("╠════════╬══════════════════════════╬════════════════════╬══════════════════════╬═══════════╣\n");
}

/**
 * @brief Display a single driver's information.
 */
void displayDriver(Driver driver, int index)
{
    printf("║  %-5d ║ %-24s ║ %-18s ║ %-20s ║ %-9.2f ║\n",
           index + 1, driver.name, driver.license_no, driver.route, driver.kms);
}

/**
 * @brief Display the footer of the driver details table.
 */
void displayFooter()
{
    printf("╚════════╩══════════════════════════╩════════════════════╩══════════════════════╩═══════════╝\n");
}

/**
 * @brief Display all driver details in a formatted table.
 */
void displayDriverDetails(Driver *drivers, int n)
{
    displayHeader();

    for (int i = 0; i < n; i++)
    {
        displayDriver(drivers[i], i);

        if (i < n - 1)
        {
            printf("╠════════╬══════════════════════════╬════════════════════╬══════════════════════╬═══════════╣\n");
        }
    }

    displayFooter();
}

/**
 * @brief Free dynamically allocated memory.
 */
void freeMemory(Driver *drivers)
{
    free(drivers);
}

/**
 * @brief Main function.
 */
int main()
{
    printf("======= Rahul B. TRAVEL AGENCY DRIVER MANAGEMENT SYSTEM =======\n\n");

    // Step 1: Get number of drivers
    int numDrivers = getDriverCount();

    // Step 2: Allocate memory
    Driver *drivers = allocateMemory(numDrivers);

    // Step 3: Input all driver details
    getAllDriverDetails(drivers, numDrivers);

    // Step 4: Display all driver details
    displayDriverDetails(drivers, numDrivers);

    // Step 5: Free allocated memory
    freeMemory(drivers);

    return 0;
}
