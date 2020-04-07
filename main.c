#include "turtle.h"
#include "color.h"
#include "window.h"

#include <ncurses.h>

#include <stdlib.h>

int main(void)
{
        initscr();
        noecho();
        curs_set(0);

        color_init();

        Window game_win, stats_win;
        window_init(&game_win, GAME_WIN_WIDTH, GAME_WIN_HEIGHT, 0, 0);
        window_init(&stats_win, STATS_WIN_WIDTH, STATS_WIN_HEIGHT, 0, GAME_WIN_HEIGHT);

        Turtle t;
        turtle_init(&t, '&', GREEN_BLACK);

        for (;;) {
                turtle_update(&t);
                /* turtle_draw(&t); */
                wrefresh(game_win.surface);
                wrefresh(stats_win.surface);
        }

        endwin();
        return EXIT_SUCCESS;
}
