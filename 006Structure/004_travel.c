/*
you manage a travel agecy and you want your n = 3 (for simplicity ) drivers to input their following details create a structure
1. Name 
2. Driving Lic No. 
3. Route
4. Kms
5. ..... 
your program should be able to take n as input and your drivers will start inputting their detaisl one by one 

your program should details of the drivers in a beutiful fashion.
Note: use the concept of structures
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Using typedef struct for Driver
typedef struct {
    char name[50];
    char license_no[20];
    char route[100];
    float kms;
} Driver;

// Function to get the number of drivers from user
int getDriverCount() {
    int n;
    printf("Enter the number of drivers: ");
    scanf("%d", &n);
    return n;
}

// Function to allocate memory for drivers
Driver* allocateMemory(int n) {
    Driver *drivers = (Driver *)malloc(n * sizeof(Driver));
    
    if (drivers == NULL) {
        printf("Memory allocation failed. Exiting program.\n");
        exit(1);
    }
    
    return drivers;
}

// Function to input driver details
void inputDriverDetails(Driver *driver, int driverNumber) {
    printf("\nDriver #%d\n", driverNumber);
    printf("==================\n");
    
    printf("Name: ");
    scanf(" %[^\n]s", driver->name);
    
    printf("Driving License No: ");
    scanf(" %[^\n]s", driver->license_no);
    
    printf("Route: ");
    scanf(" %[^\n]s", driver->route);
    
    printf("Distance (in Kms): ");
    scanf("%f", &driver->kms);
}

// Function to get details for all drivers
void getAllDriverDetails(Driver *drivers, int n) {
    for (int i = 0; i < n; i++) {
        inputDriverDetails(&drivers[i], i+1);
    }
}

// Function to draw a horizontal line in the table
void drawLine(int width) {
    printf("+");
    for (int i = 0; i < width; i++) {
        printf("-");
    }
    printf("+\n");
}

// Function to display header of the table
void displayHeader() {
    printf("\n\n");
    printf("╔════════════════════════════════════════════════════════════════════════════════════╗\n");
    printf("║                        TRAVEL AGENCY DRIVER DETAILS                                ║\n");
    printf("╠════════╦══════════════════════════╦════════════════════╦══════════════════════╦═══════════╣\n");
    printf("║  No.   ║          Name            ║    License No.     ║        Route         ║    Kms    ║\n");
    printf("╠════════╬══════════════════════════╬════════════════════╬══════════════════════╬═══════════╣\n");
}

// Function to display a single driver's details
void displayDriver(Driver driver, int index) {
    printf("║  %-5d ║ %-24s ║ %-18s ║ %-20s ║ %-9.2f ║\n", 
           index+1, driver.name, driver.license_no, driver.route, driver.kms);
}

// Function to display footer of the table
void displayFooter() {
    printf("╚════════╩══════════════════════════╩════════════════════╩══════════════════════╩═══════════╝\n");
}

// Function to display all driver details in a beautiful table
void displayDriverDetails(Driver *drivers, int n) {
    displayHeader();
    
    for (int i = 0; i < n; i++) {
        displayDriver(drivers[i], i);
        
        // Add a separator line between drivers (except after the last one)
        if (i < n-1) {
            printf("╠════════╬══════════════════════════╬════════════════════╬══════════════════════╬═══════════╣\n");
        }
    }
    
    displayFooter();
}

// Function to free allocated memory
void freeMemory(Driver *drivers) {
    free(drivers);
}

// Main function with only function calls
int main() {
    printf("======= TRAVEL AGENCY DRIVER MANAGEMENT SYSTEM =======\n\n");
    
    // Get number of drivers
    int numDrivers = getDriverCount();
    
    // Allocate memory for drivers
    Driver *drivers = allocateMemory(numDrivers);
    
    // Get details for all drivers
    getAllDriverDetails(drivers, numDrivers);
    
    // Display all driver details in a beautiful table
    displayDriverDetails(drivers, numDrivers);
    
    // Free allocated memory
    freeMemory(drivers);
    
    return 0;
}