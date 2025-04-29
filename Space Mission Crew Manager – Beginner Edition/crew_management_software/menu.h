/**
 * File: menu.h
 * Description: Header file for menu operations
 * Author: Rahul Bari
 * Date: April 29, 2025
 */

 #ifndef SMMCS_MENU_H   /* Changed to project-specific header guard */
 #define SMMCS_MENU_H
  
 #include "astronaut.h"
  
 /* Function prototypes */
 void displayWelcomeMessage(void);
 int displayMainMenu(void);
 void handleMenuChoice(int choice, Astronaut** astronauts, int* count, int* running);
 
 /* Declare utility function used in this module */
 void clearInputBuffer(void);
  
 #endif /* SMMCS_MENU_H */