/* test_logic.c - Test case for game logic */
#include <stdio.h>
#include <assert.h>
#include "game_logic.h"

void test_determine_winner() {
    printf("Running winner determination tests...\n");
    
    // Test all possible scenarios
    
    // Ties
    assert(determineWinner(ROCK, ROCK) == 0);
    assert(determineWinner(PAPER, PAPER) == 0);
    assert(determineWinner(SCISSORS, SCISSORS) == 0);
    
    // Player wins
    assert(determineWinner(ROCK, SCISSORS) == 1);
    assert(determineWinner(PAPER, ROCK) == 1);
    assert(determineWinner(SCISSORS, PAPER) == 1);
    
    // Computer wins
    assert(determineWinner(ROCK, PAPER) == -1);
    assert(determineWinner(PAPER, SCISSORS) == -1);
    assert(determineWinner(SCISSORS, ROCK) == -1);
    
    printf("All winner determination tests passed!\n");
}

void test_choice_to_string() {
    printf("Running choice to string tests...\n");
    
    assert(strcmp(choiceToString(ROCK), "Rock") == 0);
    assert(strcmp(choiceToString(PAPER), "Paper") == 0);
    assert(strcmp(choiceToString(SCISSORS), "Scissors") == 0);
    assert(strcmp(choiceToString(4), "Unknown") == 0);
    
    printf("All choice to string tests passed!\n");
}

int main() {
    printf("Starting game logic tests...\n");
    
    test_determine_winner();
    test_choice_to_string();
    
    printf("All tests passed successfully!\n");
    
    return 0;
}

/* To compile and run the test:
 * gcc -o test_logic test_logic.c game_logic.c -I. 
 * ./test_logic
 */
