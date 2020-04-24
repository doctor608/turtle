#include "menu.h"
#include "turtle.h"

#include <ncurses.h>

#include <stdlib.h>
#include <string.h>

int main(void)
{
        /* Don't touch us! */
        initscr();
        keypad(stdscr, TRUE);
        noecho();
        curs_set(0);
        start_color();
        /* End */

        Turtle t;
        turtle_init(&t, "skins/turtle.txt");

        menu_init(); // init menu_win
        MenuChoice choice = menu_mainloop();
        clear();

        switch (choice) {
        case MENU_PLAY: {
                halfdelay(1);
                for (;;) {
                        int ch = getch();

                        turtle_update(&t, ch);
                        turtle_draw(&t);

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
