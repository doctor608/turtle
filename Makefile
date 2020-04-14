C_FLAGS = -W -Wall -Wextra
C_LIBS = -lcurses

turtle.o: turtle.c
	gcc -c $(C_FLAGS) $^ $(C_LIBS)

window.o: window.c
	gcc -c $(C_FLAGS) $^ $(C_LIBS)

console.o: console.c
	gcc -c $(C_FLAGS) $^ $(C_LIBS)

turtle: main.c turtle.o window.o console.o
	gcc $(C_FLAGS) $^ $(C_LIBS) -o $@
