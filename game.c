#include "turtle.h"
#include "color.h"

#include <ncurses.h>

#include <stdlib.h>

int main(void)
{
        initscr();  // <-- Initialize ncurses.
        noecho();  // <-- Do not print on the screen.
        curs_set(0); // <-- hide cursor

        color_init();

        Turtle t;
        turtle_init(&t, '&', GREEN_BLACK);  // <- Create a Turtle

        int ch;
        for (;;) {
                if ((ch = getch()) != ERR) {

                        switch (ch) {
                        case 'h':
                                turtle_move(&t, LEFT);
                                break;
                        case 'j':
                                turtle_move(&t, DOWN);
                                break;
                        case 'k':
                                turtle_move(&t, UP);
                                break;
                        case 'l':
                                turtle_move(&t, RIGHT);
                                break;
                        }
                }

                turtle_draw(&t);
                refresh();  // <-- Clear window
        }

        endwin();  // <-- Restore terminal settings.

        return EXIT_SUCCESS;
}
