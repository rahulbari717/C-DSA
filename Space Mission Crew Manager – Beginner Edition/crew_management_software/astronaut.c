/**
 * File: astronaut.c
 * Description: Implementation of astronaut-related functions
 * Author: Rahul Bari
 * Date: April 29, 2025
 */

/* Headers and Includes */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>  /* Added for tolower() function */
#include "astronaut.h"
 #include "utils.h"

/**
 * Validates astronaut ID format (A###)
 * @param id ID string to validate
 * @return 1 if valid, 0 if invalid
 */
int isValidID(const char* id) {
    if (id == NULL || strlen(id) != 4) {
        return 0;
    }
    
    if (!isupper(id[0])) {
        return 0;
    }
    
    for (int i = 1; i < 4; i++) {
        if (!isdigit(id[i])) {
            return 0;
        }
    }
    
    return 1;
}

/**
 * Allocates memory for astronaut array - Dynamic Memory Allocation
 * @param count Number of astronauts
 * @return Pointer to allocated array or NULL on failure
 */
Astronaut* allocateAstronautMemory(int count) {
    if (count <= 0) {
        fprintf(stderr, "Error: Invalid astronaut count for allocation.\n");
        return NULL;
    }
    
    /* Using malloc to allocate memory dynamically on heap */
    Astronaut* ptr = (Astronaut*)malloc(count * sizeof(Astronaut));
    
    /* Error handling for memory allocation failure */
    if (ptr == NULL) {
        fprintf(stderr, "Error: Memory allocation failed.\n");
        return NULL;
    }
    
    /* Initialize memory to prevent undefined behavior */
    memset(ptr, 0, count * sizeof(Astronaut));
    
    return ptr;
}

/**
 * Gets details for astronauts - Input and Output functions
 * @param astronauts Pointer to pointer of astronaut array (for reallocation)
 * @param count Pointer to astronaut count (may be updated)
 */
void getAstronautDetails(Astronaut** astronauts, int* count) {
    if (astronauts == NULL || count == NULL) {
        fprintf(stderr, "Error: Invalid pointers passed to getAstronautDetails\n");
        return;
    }
    
    int numAstronauts;
    
    /* Input validation with loop - Control Flow */
    do {
        printf("Enter number of astronauts to register: ");
        if (scanf("%d", &numAstronauts) != 1) {
            printf("Invalid input. Please enter a number.\n");
            clearInputBuffer();
            continue;
        }
        
        if (numAstronauts <= 0) {
            printf("Number of astronauts must be greater than zero.\n");
        }
    } while (numAstronauts <= 0);
    
    clearInputBuffer();
    
    /* Allocate or reallocate memory */
    if (*astronauts == NULL) {
        *astronauts = allocateAstronautMemory(numAstronauts);
        if (*astronauts == NULL) {
            return;  /* Memory allocation failed */
        }
        *count = numAstronauts;
    } else {
        /* Using realloc to resize existing array - Dynamic Memory */
        int newCount = *count + numAstronauts;
        Astronaut* newPtr = (Astronaut*)realloc(*astronauts, newCount * sizeof(Astronaut));
        
        if (newPtr == NULL) {
            fprintf(stderr, "Error: Memory reallocation failed.\n");
            return;
        }
        
        /* Initialize newly allocated memory */
        memset(&newPtr[*count], 0, numAstronauts * sizeof(Astronaut));
        *astronauts = newPtr;
    }
    
    /* Loop for getting details of each astronaut */
    for (int i = *count; i < *count + numAstronauts; i++) {
        printf("\n==== Astronaut %d Details ====\n", i+1);
        
        /* String input with buffer overflow protection */
        printf("Name: ");
        fgets((*astronauts)[i].name, MAX_NAME_LENGTH, stdin);
        (*astronauts)[i].name[strcspn((*astronauts)[i].name, "\n")] = 0;
        
        /* Integer input with validation */
        int validInput = 0;
        while (!validInput) {
            printf("Age: ");
            if (scanf("%d", &(*astronauts)[i].age) != 1) {
                printf("Invalid age. Please enter a number.\n");
                clearInputBuffer();
                continue;
            }
            
            if ((*astronauts)[i].age < 18 || (*astronauts)[i].age > 65) {
                printf("Age must be between 18 and 65.\n");
                continue;
            }
            
            validInput = 1;
        }
        clearInputBuffer();
        
        /* ID input with validation */
        validInput = 0;
        while (!validInput) {
            printf("ID (format A###): ");
            fgets((*astronauts)[i].id, MAX_ID_LENGTH, stdin);
            (*astronauts)[i].id[strcspn((*astronauts)[i].id, "\n")] = 0;
            
            if (!isValidID((*astronauts)[i].id)) {
                printf("Invalid ID format. Please use format A### (one uppercase letter followed by 3 digits).\n");
                continue;
            }
            
            validInput = 1;
        }
        
        /* Role selection with validation using enum */
        validInput = 0;
        while (!validInput) {
            printf("Role (1=Pilot, 2=Scientist): ");
            int roleChoice;
            if (scanf("%d", &roleChoice) != 1) {
                printf("Invalid choice. Please enter 1 or 2.\n");
                clearInputBuffer();
                continue;
            }
            
            if (roleChoice != ROLE_PILOT && roleChoice != ROLE_SCIENTIST) {
                printf("Invalid role. Please enter 1 for Pilot or 2 for Scientist.\n");
                clearInputBuffer();
                continue;
            }
            
            (*astronauts)[i].role = roleChoice;
            validInput = 1;
        }
        clearInputBuffer();
        
        /* Get role-specific details using union */
        if ((*astronauts)[i].role == ROLE_PILOT) {
            validInput = 0;
            while (!validInput) {
                printf("Flight hours: ");
                if (scanf("%d", &(*astronauts)[i].roleDetails.flightHours) != 1) {
                    printf("Invalid input. Please enter a number.\n");
                    clearInputBuffer();
                    continue;
                }
                
                if ((*astronauts)[i].roleDetails.flightHours < 0) {
                    printf("Flight hours cannot be negative.\n");
                    continue;
                }
                
                validInput = 1;
            }
            clearInputBuffer();
        } else {
            printf("Specialization: ");
            fgets((*astronauts)[i].roleDetails.specialization, MAX_SPECIALIZATION_LENGTH, stdin);
            (*astronauts)[i].roleDetails.specialization[strcspn((*astronauts)[i].roleDetails.specialization, "\n")] = 0;
        }
        
        /* Success message after registration */
        printf("\n✅ Astronaut details successfully registered in our local database!\n");
    }
    
    /* Update count */
    *count = *count + numAstronauts;
}

/**
 * Displays all astronaut records - Formatted Output
 * @param astronauts Array of astronauts
 * @param count Number of astronauts
 */
void displayAllAstronauts(Astronaut* astronauts, int count) {
    if (astronauts == NULL || count == 0) {
        printf("No astronauts registered yet.\n");
        return;
    }
    
    printf("\n==================== ASTRONAUT DIRECTORY ====================\n");
    printf("%-10s | %-20s | %-5s | %-12s | %-20s\n", 
           "ID", "Name", "Age", "Role", "Specialty");
    printf("----------------------------------------------------------\n");
    
    /* Iterate through array of structures */
    for (int i = 0; i < count; i++) {
        printf("%-10s | %-20s | %-5d | ", 
               astronauts[i].id, 
               astronauts[i].name, 
               astronauts[i].age);
        
        /* Role-specific details using switch statement */
        switch(astronauts[i].role) {
            case ROLE_PILOT:
                printf("%-12s | %-20d hours\n", "Pilot", astronauts[i].roleDetails.flightHours);
                break;
            case ROLE_SCIENTIST:
                printf("%-12s | %-20s\n", "Scientist", astronauts[i].roleDetails.specialization);
                break;
            default:
                printf("%-12s | %-20s\n", "Unknown", "N/A");
        }
    }
    printf("==========================================================\n");
}

/**
 * Search menu - Function pointer usage
 * @param astronauts Array of astronauts
 * @param count Number of astronauts
 */
void searchAstronauts(Astronaut* astronauts, int count) {
    if (astronauts == NULL || count == 0) {
        printf("No astronauts registered yet.\n");
        return;
    }
    
    /* Function pointers array for different search options */
    typedef void (*SearchFunction)(Astronaut*, int);
    SearchFunction searchFunctions[3] = {
        searchAstronautById,
        searchAstronautByName,
        searchAstronautByRole
    };
    
    int choice;
    
    /* Search submenu */
    printf("\n----- Search Options -----\n");
    printf("1. Search by ID\n");
    printf("2. Search by Name\n");
    printf("3. Search by Role\n");
    printf("Enter choice (1-3): ");
    
    /* Input validation */
    if (scanf("%d", &choice) != 1 || choice < 1 || choice > 3) {
        printf("Invalid choice. Returning to main menu.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();
    
    /* Call appropriate search function using function pointer */
    searchFunctions[choice-1](astronauts, count);
}

/**
 * Searches for an astronaut by ID - String comparison
 * @param astronauts Array of astronauts
 * @param count Number of astronauts
 */
void searchAstronautById(Astronaut* astronauts, int count) {
    if (astronauts == NULL || count == 0) {
        printf("No astronauts registered yet.\n");
        return;
    }
    
    char searchId[MAX_ID_LENGTH];
    int found = 0;
    
    printf("Enter ID to search: ");
    fgets(searchId, MAX_ID_LENGTH, stdin);
    searchId[strcspn(searchId, "\n")] = 0;
    
    /* Linear search through array */
    for (int i = 0; i < count; i++) {
        /* String comparison using library function */
        if (strcmp(astronauts[i].id, searchId) == 0) {
            printf("\n----- Astronaut Found -----\n");
            printf("ID: %s\n", astronauts[i].id);
            printf("Name: %s\n", astronauts[i].name);
            printf("Age: %d\n", astronauts[i].age);
            
            if (astronauts[i].role == ROLE_PILOT) {
                printf("Role: Pilot\n");
                printf("Flight Hours: %d\n", astronauts[i].roleDetails.flightHours);
            } else {
                printf("Role: Scientist\n");
                printf("Specialization: %s\n", astronauts[i].roleDetails.specialization);
            }
            
            found = 1;
            break;
        }
    }
    
    /* Error handling */
    if (!found) {
        printf("❌ Astronaut with ID '%s' not found.\n", searchId);
    }
}

/**
 * Searches for astronauts by name - Partial string matching
 * @param astronauts Array of astronauts
 * @param count Number of astronauts
 */
void searchAstronautByName(Astronaut* astronauts, int count) {
    if (astronauts == NULL || count == 0) {
        printf("No astronauts registered yet.\n");
        return;
    }
    
    char searchName[MAX_NAME_LENGTH];
    int found = 0;
    
    printf("Enter name (or part of name) to search: ");
    fgets(searchName, MAX_NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = 0;
    
    /* Convert search term to lowercase for case-insensitive search */
    for (int i = 0; searchName[i]; i++) {
        searchName[i] = tolower((unsigned char)searchName[i]);
    }
    
    printf("\n----- Search Results -----\n");
    
    /* Search with partial string matching */
    for (int i = 0; i < count; i++) {
        /* Create a lowercase copy of the astronaut name */
        char nameLower[MAX_NAME_LENGTH];
        strcpy(nameLower, astronauts[i].name);
        
        for (int j = 0; nameLower[j]; j++) {
            nameLower[j] = tolower((unsigned char)nameLower[j]);
        }
        
        /* Check if search term is contained in name */
        if (strstr(nameLower, searchName) != NULL) {
            printf("ID: %s, Name: %s, ", 
                   astronauts[i].id, astronauts[i].name);
            
            if (astronauts[i].role == ROLE_PILOT) {
                printf("Pilot, Flight Hours: %d\n", astronauts[i].roleDetails.flightHours);
            } else {
                printf("Scientist, Specialization: %s\n", astronauts[i].roleDetails.specialization);
            }
            
            found = 1;
        }
    }
    
    if (!found) {
        printf("❌ No astronauts found with name containing '%s'.\n", searchName);
    }
}

/**
 * Searches for astronauts by role
 * @param astronauts Array of astronauts
 * @param count Number of astronauts
 */
void searchAstronautByRole(Astronaut* astronauts, int count) {
    if (astronauts == NULL || count == 0) {
        printf("No astronauts registered yet.\n");
        return;
    }
    
    int roleChoice;
    int found = 0;
    
    printf("Enter role to search (1=Pilot, 2=Scientist): ");
    if (scanf("%d", &roleChoice) != 1 || (roleChoice != ROLE_PILOT && roleChoice != ROLE_SCIENTIST)) {
        printf("Invalid role choice.\n");
        clearInputBuffer();
        return;
    }
    clearInputBuffer();
    
    printf("\n----- %s List -----\n", (roleChoice == ROLE_PILOT) ? "Pilot" : "Scientist");
    
    /* Filtered display based on role */
    for (int i = 0; i < count; i++) {
        if (astronauts[i].role == roleChoice) {
            printf("ID: %s, Name: %s, Age: %d, ", 
                   astronauts[i].id, astronauts[i].name, astronauts[i].age);
                   
            if (roleChoice == ROLE_PILOT) {
                printf("Flight Hours: %d\n", astronauts[i].roleDetails.flightHours);
            } else {
                printf("Specialization: %s\n", astronauts[i].roleDetails.specialization);
            }
            
            found = 1;
        }
    }
    
    if (!found) {
        printf("❌ No astronauts with the selected role found.\n");
    }
}

/**
 * Frees allocated memory - Memory Management
 * @param astronauts Array of astronauts
 */
void freeAstronautMemory(Astronaut* astronauts) {
    if (astronauts != NULL) {
        free(astronauts);
    }
}

