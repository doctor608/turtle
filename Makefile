C_FLAGS = -W -Wall -Wextra

turtle.o: turtle.c turtle.h
	gcc -c $(C_FLAGS) turtle.c -lcurses -o turtle.o

turtle: game.c turtle.o
	gcc $(C_FLAGS) game.c turtle.o -lcurses -o turtle

