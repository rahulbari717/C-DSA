# Rock, Paper, Scissors - Quick Start Guide

## Running the Game

1. **Open Terminal**: Launch your Ubuntu terminal

2. **Navigate to the game directory**:
   ```bash
   cd ~/Documents/C-DSA/Scisso_Paper_Rock_game
   ```

3. **Compile the game**:
   ```bash
   make
   ```

4. **Run the game**:
   ```bash
   ./rock_paper_scissors
   ```

5. **Follow on-screen instructions** to play:
   - Enter number of rounds (1-10)
   - Choose your move each round (1=Rock, 2=Paper, 3=Scissors)
   - Press Enter between rounds

## Running Test Cases

1. **Compile the test cases**:
   ```bash
   gcc -o test_logic test_logic.c game_logic.c -I.
   ```

2. **Run the tests**:
   ```bash
   ./test_logic
   ```

3. **Verify test results**: All tests should pass with success messages

## File Structure

- **main.c**: Main game controller
- **game_logic.c/h**: Game rules implementation
- **input_handler.c/h**: User input management
- **display.c/h**: User interface functions
- **test_logic.c**: Game logic test cases

## Command Summary

| Command | Description |
|---------|-------------|
| `make` | Compile the full game |
| `./rock_paper_scissors` | Run the game |
| `gcc -o test_logic test_logic.c game_logic.c -I.` | Compile tests |
| `./test_logic` | Run test cases |
| `make clean` | Remove compiled files |
