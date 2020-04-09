C_FLAGS = -W -Wall -Wextra
C_LIBS = -lcurses

turtle.o: turtle.c turtle.h
	gcc -c $(C_FLAGS) turtle.c $(C_LIBS) -o turtle.o

turtle: main.c turtle.o
	gcc $(C_FLAGS) main.c turtle.o $(C_LIBS) -o turtle

