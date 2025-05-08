/* input_handler.c */
#include <stdio.h>
#include "input_handler.h"
#include "game_logic.h"

int getPlayerChoice() {
    int choice = 0;
    int valid = 0;
    
    while (!valid) {
        printf("\nEnter your choice (1 for Rock, 2 for Paper, 3 for Scissors): ");
        if (scanf("%d", &choice) != 1) {
            // Clear input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        
        // Clear input buffer
        while (getchar() != '\n');
        
        if (choice >= 1 && choice <= 3) {
            valid = 1;
        } else {
            printf("Invalid choice. Please enter 1, 2, or 3.\n");
        }
    }
    
    return choice;
}

int getRoundsInput() {
    int rounds = 0;
    int valid = 0;
    
    while (!valid) {
        printf("How many rounds would you like to play? (1-5): ");
        if (scanf("%d", &rounds) != 1) {
            // Clear input buffer
            while (getchar() != '\n');
            printf("Invalid input. Please enter a number.\n");
            continue;
        }
        
        // Clear input buffer
        while (getchar() != '\n');
        
        if (rounds >= 1 && rounds <= 5) {
            valid = 1;
        } else {
            printf("Please enter a number between 1 and 5.\n");
        }
    }
    
    return rounds;
}

int getPlayAgainChoice() {
    char choice;
    int valid = 0;
    int playAgain = 0;
    
    while (!valid) {
        printf("\nWould you like to play again? (y/n): ");
        scanf(" %c", &choice);
        
        // Clear input buffer
        while (getchar() != '\n');
        
        if (choice == 'y' || choice == 'Y') {
            playAgain = 1;
            valid = 1;
        } else if (choice == 'n' || choice == 'N') {
            playAgain = 0;
            valid = 1;
        } else {
            printf("Invalid input. Please enter 'y' or 'n'.\n");
        }
    }
    
    return playAgain;
}

