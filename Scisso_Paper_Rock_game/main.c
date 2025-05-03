/* main.c */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "game_logic.h"
#include "input_handler.h"
#include "display.h"

int main() {
    int playerScore = 0;
    int computerScore = 0;
    int round = 1;
    int totalRounds;
    int playerChoice, computerChoice;
    int playAgain = 1;

    // Seed random number generator
    srand(time(NULL));
    
    // Display welcome message
    displayWelcome();
    
    while (playAgain) {
        // Get total rounds from user
        totalRounds = getRoundsInput();
        
        // Reset scores for new game
        playerScore = 0;
        computerScore = 0;
        round = 1;
        
        // Main game loop
        while (round <= totalRounds) {
            // Display round information
            displayRoundInfo(round, totalRounds, playerScore, computerScore);
            
            // Get player's choice
            playerChoice = getPlayerChoice();
            
            // Generate computer's choice
            computerChoice = generateComputerChoice();
            
            // Display choices
            displayChoices(playerChoice, computerChoice);
            
            // Determine round winner
            int result = determineWinner(playerChoice, computerChoice);
            
            // Update scores
            if (result == 1) {
                playerScore++;
                displayRoundResult("You win this round!");
            } else if (result == -1) {
                computerScore++;
                displayRoundResult("Computer wins this round!");
            } else {
                displayRoundResult("It's a tie!");
            }
            
            round++;
            
            // Brief pause between rounds
            printf("\nPress Enter to continue...");
            while (getchar() != '\n');
            getchar();  // Capture the Enter key
        }
        
        // Display final results
        displayFinalResults(playerScore, computerScore);
        
        // Ask to play again
        playAgain = getPlayAgainChoice();
    }
    
    // Display goodbye message
    displayGoodbye();
    
    return 0;
}
