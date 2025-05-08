CC = gcc
CFLAGS = -Wall -Wextra -g

all: rock_paper_scissors

rock_paper_scissors: main.o game_logic.o input_handler.o display.o
	@$(CC) $(CFLAGS) -o rock_paper_scissors main.o game_logic.o input_handler.o display.o

main.o: main.c game_logic.h input_handler.h display.h
	@$(CC) $(CFLAGS) -c main.c

game_logic.o: game_logic.c game_logic.h
	@$(CC) $(CFLAGS) -c game_logic.c

input_handler.o: input_handler.c input_handler.h game_logic.h
	@$(CC) $(CFLAGS) -c input_handler.c

display.o: display.c display.h game_logic.h
	@$(CC) $(CFLAGS) -c display.c

clean:
	rm -f *.o rock_paper_scissors

run: rock_paper_scissors
	@./rock_paper_scissors

.PHONY: all clean run