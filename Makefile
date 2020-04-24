C_FLAGS = -W -Wall -Wextra
C_LIBS = -lcurses

turtle.o: turtle.c
	gcc -c $(C_FLAGS) $^ $(C_LIBS)

menu.o: menu.c
	gcc -c $(C_FLAGS) $^ $(C_LIBS)

turtle: main.c turtle.o menu.o
	gcc $(C_FLAGS) $^ $(C_LIBS) -o $@