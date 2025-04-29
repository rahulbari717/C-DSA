/**
 * File: main.c
 * Description: Main entry point for Space Mission Crew Management System
 * Author: Rahul Bari
 * Date: April 29, 2025
 */

/* Header Files and Modular Programming */
#include <stdio.h>
#include <stdlib.h>
#include "astronaut.h"
#include "menu.h"
#include "fileio.h"

/**
 * Main function - Program entry point
 * Command Line Arguments can be processed here if needed
 */
int main(int argc, char *argv[]) {
    /* Initialize variables with default values */
    int running = 1;
    Astronaut* astronauts = NULL;
    int astronautCount = 0;
    
    /* Use function pointer array for menu operations */
    displayWelcomeMessage();
    
    /* Main loop */
    while (running) {
        int choice = displayMainMenu();
        handleMenuChoice(choice, &astronauts, &astronautCount, &running);
    }
    
    /* Clean exit - release all resources */
    if (astronauts != NULL) {
        freeAstronautMemory(astronauts);
        astronauts = NULL;
    }
    
    return 0;
}