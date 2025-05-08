/* game_logic.c */
#include <stdio.h>
#include <assert.h>
#include <string.h>  /* Add this line for strcmp function */
#include <stdlib.h>
#include "game_logic.h"

int generateComputerChoice() {
    // Generate a random number between 1 and 3
    return (rand() % 3) + 1;
}

int determineWinner(int playerChoice, int computerChoice) {
    // Return values:
    // 1 = player wins
    // 0 = tie
    // -1 = computer wins
    
    // If both choose the same, it's a tie
    if (playerChoice == computerChoice) {
        return 0;
    }
    
    // Player wins scenarios
    if ((playerChoice == ROCK && computerChoice == SCISSORS) ||
        (playerChoice == PAPER && computerChoice == ROCK) ||
        (playerChoice == SCISSORS && computerChoice == PAPER)) {
        return 1;
    }
    
    // Otherwise computer wins
    return -1;
}

const char* choiceToString(int choice) {
    switch (choice) {
        case ROCK:
            return "Rock";
        case PAPER:
            return "Paper";
        case SCISSORS:
            return "Scissors";
        default:
            return "Unknown";
    }
}
