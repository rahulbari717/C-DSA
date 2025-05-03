# Rock, Paper, Scissors Game

A modular C implementation of the classic Rock, Paper, Scissors game.

## Table of Contents
- [Overview](#overview)
- [Project Structure](#project-structure)
- [Installation](#installation)
- [How to Play](#how-to-play)
- [Running Tests](#running-tests)
- [Game Features](#game-features)
- [Development Notes](#development-notes)

## Overview

This is a terminal-based Rock, Paper, Scissors game implemented in C. The game allows you to play against the computer, with options to select the number of rounds and track scores.

## Project Structure

```
Scisso_Paper_Rock_game/
├── main.c             # Main program entry point
├── game_logic.h       # Game rules and logic declarations
├── game_logic.c       # Game rules and logic implementation
├── input_handler.h    # User input handling declarations
├── input_handler.c    # User input handling implementation
├── display.h          # UI display declarations
├── display.c          # UI display implementation
├── makefile           # Build configuration
├── test_logic.c       # Test cases for game logic
└── README.md          # This documentation
```

## Installation

### Prerequisites
- GCC compiler
- Make utility
- Ubuntu 24.04 or similar Linux environment

### Building the Game

1. Clone or download the project to your local machine:
   ```
   git clone https://github.com/yourusername/Scisso_Paper_Rock_game.git
   cd Scisso_Paper_Rock_game
   ```

2. Compile the game using make:
   ```
   make
   ```

3. Run the game:
   ```
   ./rock_paper_scissors
   ```

## How to Play

1. When you start the game, you'll see a welcome message and game rules.
2. Enter the number of rounds you want to play (between 1 and 10).
3. For each round:
   - Enter your choice:
     - 1 for Rock
     - 2 for Paper
     - 3 for Scissors
   - The computer will randomly select its choice.
   - The round winner will be displayed along with updated scores.
   - Press Enter to continue to the next round.
4. After all rounds are played, the final results will be displayed.
5. You can choose to play again or exit the game.

### Game Rules
- Rock crushes Scissors
- Scissors cuts Paper
- Paper covers Rock

## Running Tests

The project includes tests to verify the game logic functions correctly.

1. Compile the test cases:
   ```
   gcc -o test_logic test_logic.c game_logic.c -I.
   ```

2. Run the tests:
   ```
   ./test_logic
   ```

3. Verify that all tests pass. You should see output similar to:
   ```
   Starting game logic tests...
   Running winner determination tests...
   All winner determination tests passed!
   Running choice to string tests...
   All choice to string tests passed!
   All tests passed successfully!
   ```

## Game Features

- Modular design with clear separation of concerns
- Multiple rounds per game session
- Score tracking
- Input validation
- Option to play again
- Clean terminal-based user interface
- Well-commented code

## Development Notes

### Code Organization

- **Main Program (main.c)**: Controls game flow with modular functions.
- **Game Logic (game_logic.c)**: Core game rules and winner determination.
- **Input Handler (input_handler.c)**: Manages and validates user input.
- **Display (display.c)**: Handles all terminal output for user interface.

### Technical Details

- Uses static functions and variables for proper encapsulation
- Implements extern declarations for cross-module function access
- Defines macros for game constants
- Includes comprehensive input validation
- Provides detailed comments throughout the codebase

### Cleaning Up

To remove object files and the executable:
```
make clean
```
