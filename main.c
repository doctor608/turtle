#include "window.h"
#include "console.h"
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
        turtle_init(&t);

        menu_init(); // init menu_win

        WINDOW* game_win = newwin(GAME_WIN_HEIGHT, GAME_WIN_WIDTH, 0, 0);

        MenuChoice choice = menu_mainloop();

        switch (choice) {
        case MENU_SETTINGS:
                break;
        case MENU_EXIT:
                break;
        case MENU_PLAY:
                for (;;) {
                        halfdelay(1);
                        int ch = wgetch(game_win);

                        turtle_update(&t, game_win, ch);
                        turtle_draw(&t, game_win);

                        window_update(game_win);
                }
                break;
        }

        endwin();
        return EXIT_SUCCESS;
}
