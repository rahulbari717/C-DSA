/* display.c */
#include <stdio.h>
#include "display.h"
#include "game_logic.h"

void displayWelcome() {
    printf("\n");
    printf("*************************************************\n");
    printf("*                                               *\n");
    printf("*             ROCK, PAPER, SCISSORS             *\n");
    printf("*                                               *\n");
    printf("*************************************************\n");
    printf("\n");
    printf("Welcome to the Rock, Paper, Scissors game!\n");
    printf("\n");
    printf("Game Rules:\n");
    printf("- Rock crushes Scissors\n");
    printf("- Scissors cuts Paper\n");
    printf("- Paper covers Rock\n");
    printf("\n");
}

void displayRoundInfo(int round, int totalRounds, int playerScore, int computerScore) {
    printf("\n");
    printf("===================================\n");
    printf("Round %d of %d\n", round, totalRounds);
    printf("===================================\n");
    printf("Score: You %d - %d Computer\n", playerScore, computerScore);
    printf("\n");
}

void displayChoices(int playerChoice, int computerChoice) {
    printf("\n");
    printf("You chose: %s\n", choiceToString(playerChoice));
    printf("Computer chose: %s\n", choiceToString(computerChoice));
}

void displayRoundResult(const char* result) {
    printf("\n");
    printf("%s\n", result);
}

void displayFinalResults(int playerScore, int computerScore) {
    printf("\n");
    printf("===================================\n");
    printf("          FINAL RESULTS            \n");
    printf("===================================\n");
    printf("Player Score: %d\n", playerScore);
    printf("Computer Score: %d\n", computerScore);
    printf("\n");
    
    if (playerScore > computerScore) {
        printf("Congratulations! You win the game!\n");
    } else if (computerScore > playerScore) {
        printf("Computer wins the game! Better luck next time!\n");
    } else {
        printf("The game ends in a tie!\n");
    }
}

void displayGoodbye() {
    printf("\n");
    printf("Thank you for playing Rock, Paper, Scissors!\n");
    printf("Goodbye!\n");
    printf("\n");
}
