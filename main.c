#include "turtle.h"
#include "window.h"

#include <ncurses.h>

#include <stdlib.h>

int main(void)
{
        /* Don't touch us! */
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        noecho();
        curs_set(0);
        clear();
        start_color();
        /* End */

        Turtle t;
        turtle_init(&t, '&');

        WINDOW* game_win = newwin(GAME_WIN_HEIGHT, GAME_WIN_WIDTH, 0, 0);
        WINDOW* stats_win = newwin(STATS_WIN_HEIGHT, STATS_WIN_WIDTH, GAME_WIN_HEIGHT, 0);

        for (;;) {
                turtle_update(&t, game_win);
                turtle_draw(&t, game_win);
                box(game_win, 0, 0);
                wrefresh(game_win);

                turtle_stats_draw(&t, stats_win);
                box(stats_win, 0, 0);
                wrefresh(stats_win);
        }

        endwin();
        return EXIT_SUCCESS;
}
