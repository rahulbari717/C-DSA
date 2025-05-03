/* game_logic.h */
#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

// Game moves
#define ROCK 1
#define PAPER 2
#define SCISSORS 3

// Function prototypes
int generateComputerChoice();
int determineWinner(int playerChoice, int computerChoice);
const char* choiceToString(int choice);

#endif
