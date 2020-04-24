#include "menu.h"
#include "turtle.h"

#include <ncurses.h>

#include <stdlib.h>
#include <string.h>

#define BG_COLOR 10
#define TURTLE_COLOR 11

int main(void)
{
        /* Don't touch us! */
        initscr();
        keypad(stdscr, TRUE);
        noecho();
        curs_set(0);
        start_color();
        /* End */

        init_pair(BG_COLOR, COLOR_GREEN, COLOR_CYAN);
        init_pair(TURTLE_COLOR, COLOR_BLACK, COLOR_CYAN);

        Turtle t;
        turtle_init(&t, "skins/turtle.txt", TURTLE_COLOR);

        menu_init(); // init menu_win
        MenuChoice choice = menu_mainloop();
        clear();

        switch (choice) {
        case MENU_PLAY: {
                halfdelay(1);
                for (;;) {
                        bkgd(COLOR_PAIR(BG_COLOR));
                        int ch = getch();

                        turtle_update(&t, ch);
                        turtle_draw(&t);

                        box(stdscr, 0, 0);
                        refresh();
                }
        }
                break;
        case MENU_SETTINGS:
                break;
        case MENU_EXIT:
                break;
        }
        
        turtle_del(&t);
        endwin();
        return EXIT_SUCCESS;
}
