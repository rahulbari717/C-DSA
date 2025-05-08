/* display.c */
#include <stdio.h>
#include "display.h"
#include "game_logic.h"

void displayWelcome() {
    printf("\n");
    printf("   ____        _       _   _    _   _    _            ____   \n");
    printf("U |  _\"\\  u U  /\"\\  u  |'| |'|U |\"\\|u| |  |\"\\|        U | __\")u \n");
    printf(" \\\\| |_) |/  \\\\/ _ \\\\/  /| |_| |\\\\\\| |\\\\| |U | | u       \\\\|  _ \\\\/ \n");
    printf("  |  _ <    / ___ \\\\  U|  _  |u | |_| | \\\\| |/__       | |_) | \n");
    printf("  |_| \\_\\\\  /_/   \\_\\\\  |_| |_| <<\\\\___/   |_____|      |____/  \n");
    printf("  //   \\\\_  \\\\\\    >>  //   \\\\\\(__) )(    //  \\\\\\      _|| \\\\_  \n");
    printf(" (__)  (__)(__)  (__)(_\") (\"_)   (__)  (_\")(\"_)    (__) (__) \n");
    printf("\n");
    printf("  ========================================================\n");
    printf("  ||           ROCK, PAPER, SCISSORS GAME               ||\n");
    printf("  ||           Developed by: Rahul B.                   ||\n");
    printf("  ||           Date : 3rd May 2025                      ||\n");
    printf("  ========================================================\n");
    printf("\n");
    printf("  *************************************************\n");
    printf("  *                 GAME RULES                     *\n");
    printf("  *-----------------------------------------------*\n");
    printf("  *     Rock     crushes    Scissors              *\n");
    printf("  *     Scissors cuts       Paper                 *\n");
    printf("  *     Paper    covers     Rock                  *\n");
    printf("  *************************************************\n");
    printf("\n");
    printf("  Welcome to the ultimate Rock, Paper, Scissors challenge!\n");
    printf("  Are you ready to test your luck and strategy?\n");
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
