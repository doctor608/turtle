C_FLAGS = -W -Wall -Wextra
C_LIBS = -lcurses

turtle.o: turtle.c turtle.h
	gcc -c $(C_FLAGS) turtle.c $(C_LIBS) -o turtle.o

window.o: window.c window.h
	gcc -c $(C_FLAGS) window.c $(C_LIBS) -o window.o

turtle: main.c turtle.o window.o
	gcc $(C_FLAGS) main.c turtle.o window.o $(C_LIBS) -o turtle

