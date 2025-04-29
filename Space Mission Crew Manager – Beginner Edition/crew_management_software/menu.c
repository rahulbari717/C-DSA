/**
 * File: menu.c
 * Description: Implementation of menu functions
 * Author: Rahul Bari
 * Date: April 29, 2025
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include "menu.h"
 #include "fileio.h"
 #include "utils.h"
 
 /**
  * Displays welcome message with ASCII art - Enhanced Output
  */
 void displayWelcomeMessage(void) {
    printf("\n");
    printf("   ____        _       _   _    _   _    _            ____   \n");
    printf("U |  _\"\\  u U  /\"\\  u  |'| |'|U |\"\\|u| |  |\"\\|        U | __\")u \n");
    printf(" \\\\| |_) |/  \\\\/ _ \\\\/  /| |_| |\\\\\\| |\\\\| |U | | u       \\\\|  _ \\\\/ \n");
    printf("  |  _ <    / ___ \\\\  U|  _  |u | |_| | \\\\| |/__       | |_) | \n");
    printf("  |_| \\_\\\\  /_/   \\_\\\\  |_| |_| <<\\\\___/   |_____|      |____/  \n");
    printf("  //   \\\\_  \\\\\\    >>  //   \\\\\\(__) )(    //  \\\\\\      _|| \\\\_  \n");
    printf(" (__)  (__)(__)  (__)(_\") (\"_)   (__)  (_\")(\"_)    (__) (__) \n");
    printf("\n");
    printf("========================= SPACE MISSION CREW MANAGEMENT SYSTEM =========================\n");
    printf("                             Developed by: Rahul B., April 2025                         \n");
    printf("========================================================================================\n\n");
}
  
 /**
  * Displays main menu and gets user choice - User Interface
  * @return User's menu choice
  */
 int displayMainMenu(void) {
     int choice;
     int validInput = 0;
     
     /* Using do-while loop for input validation */
     do {
         /* Menu formatting for better readability */
         printf("\n");
         printf("---------------------------- Menu ----------------------------\n");
         printf("1) Register details for astronauts\n");
         printf("2) Show all astronauts\n");
         printf("3) Search astronauts (by ID, name, role)\n");
         printf("4) Export data to file\n"); 
         printf("5) Exit\n");
         printf("------------------------------------------------------------\n");
         printf("Enter your choice (1-5): ");
         
         /* Input with validation */
         if (scanf("%d", &choice) != 1) {
             printf("❌ Invalid input. Please enter a number between 1 and 5.\n");
             clearInputBuffer();
             continue;
         }
         
         if (choice < 1 || choice > 5) {
             printf("❌ Invalid choice. Please enter a number between 1 and 5.\n");
             continue;
         }
         
         validInput = 1;
     } while (!validInput);
     
     clearInputBuffer();
     return choice;
 }
 
 /**
  * Wrapper functions to match the MenuFunction type signature
  */
 void registerAstronautsWrapper(Astronaut** astronauts, int* count) {
     getAstronautDetails(astronauts, count);
 }
 
 void displayAllAstronautsWrapper(Astronaut** astronauts, int* count) {
     if (astronauts == NULL || *astronauts == NULL) {
         printf("No astronauts registered yet.\n");
         return;
     }
     displayAllAstronauts(*astronauts, *count);
 }
 
 void searchAstronautsWrapper(Astronaut** astronauts, int* count) {
     if (astronauts == NULL || *astronauts == NULL) {
         printf("No astronauts registered yet.\n");
         return;
     }
     searchAstronauts(*astronauts, *count);
 }
 
 void exportAstronautDataWrapper(Astronaut** astronauts, int* count) {
     if (astronauts == NULL || *astronauts == NULL) {
         printf("No astronauts registered yet.\n");
         return;
     }
     exportAstronautData(*astronauts, *count);
 }
 
 /**
  * Handles menu choice using function pointers - Advanced C
  * @param choice User's menu choice
  * @param astronauts Pointer to pointer of astronaut array
  * @param count Pointer to astronaut count
  * @param running Pointer to running flag
  */
 void handleMenuChoice(int choice, Astronaut** astronauts, int* count, int* running) {
     if (astronauts == NULL || count == NULL || running == NULL) {
         fprintf(stderr, "Error: Invalid pointers passed to handleMenuChoice\n");
         return;
     }
     
     /* Define function pointer type */
     typedef void (*MenuFunction)(Astronaut**, int*);
     
     /* Array of function pointers with proper wrapper functions */
     MenuFunction menuFunctions[4] = {
         registerAstronautsWrapper,      // Register astronauts
         displayAllAstronautsWrapper,    // Show all astronauts
         searchAstronautsWrapper,        // Search astronauts
         exportAstronautDataWrapper      // Export data
     };
     
     /* Handle menu choice */
     if (choice >= 1 && choice <= 4) {
         /* Call appropriate function using function pointer */
         menuFunctions[choice - 1](astronauts, count);
     } else if (choice == 5) {
         printf("Exiting program. Cleaning up resources...\n");
         
         /* Free memory before exit - Memory Management */
         if (*astronauts != NULL) {
             freeAstronautMemory(*astronauts);
             *astronauts = NULL;
         }
         
         printf("Thanks for using Crew Management System!\n");
         *running = 0;
     }
 }
   
