C_FLAGS = -W -Wall -Wextra
C_LIBS = -lcurses

color.o: color.c color.h
	gcc -c $(C_FLAGS) color.c $(C_LIBS) -o color.o

turtle.o: turtle.c turtle.h
	gcc -c $(C_FLAGS) turtle.c $(C_LIBS) -o turtle.o

turtle: game.c turtle.o color.o
	gcc $(C_FLAGS) game.c turtle.o color.o $(C_LIBS) -o turtle

