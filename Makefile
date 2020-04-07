C_FLAGS = -W -Wall -Wextra
C_LIBS = -lcurses

color.o: color.c color.h
	gcc -c $(C_FLAGS) color.c $(C_LIBS) -o color.o

window.o: window.c window.h
	gcc -c $(C_FLAGS) window.c $(C_LIBS) -o window.o

turtle.o: turtle.c turtle.h
	gcc -c $(C_FLAGS) turtle.c $(C_LIBS) -o turtle.o

turtle: main.c turtle.o window.o color.o
	gcc $(C_FLAGS) main.c turtle.o window.o color.o $(C_LIBS) -o turtle

