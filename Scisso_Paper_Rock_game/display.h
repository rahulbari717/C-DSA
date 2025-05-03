/* display.h */
#ifndef DISPLAY_H
#define DISPLAY_H

// Function prototypes
void displayWelcome();
void displayRoundInfo(int round, int totalRounds, int playerScore, int computerScore);
void displayChoices(int playerChoice, int computerChoice);
void displayRoundResult(const char* result);
void displayFinalResults(int playerScore, int computerScore);
void displayGoodbye();

#endif
