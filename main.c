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
        WINDOW* stats_win = newwin(
                STATS_WIN_HEIGHT, STATS_WIN_WIDTH, GAME_WIN_HEIGHT, 0
        );
        WINDOW* console_win = newwin(
                CONSOLE_WIN_HEIGHT, CONSOLE_WIN_WIDTH, GAME_WIN_HEIGHT, COLS / 2
        );

        for (;;) {
                turtle_update(&t, game_win);

                turtle_draw(&t, game_win);
                turtle_stats_draw(&t, stats_win);

                win_draw(game_win);
                win_draw(stats_win);
                win_draw(console_win);
        }

        endwin();
        return EXIT_SUCCESS;
}
