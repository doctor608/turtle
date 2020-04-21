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
        turtle_init(&t, '&');

        menu_init(); // init menu_win
        console_init(); // init console_win

        WINDOW* game_win = newwin(GAME_WIN_HEIGHT, GAME_WIN_WIDTH, 0, 0);
        WINDOW* stats_win = newwin(
                STATS_WIN_HEIGHT, STATS_WIN_WIDTH, GAME_WIN_HEIGHT, 0
        );

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

                        switch (ch) {
                        case 'h':
                                mvwaddch(game_win, t.y, t.x, ' ');
                                t.x -= 1;
                                break;
                        case 'j':
                                mvwaddch(game_win, t.y, t.x, ' ');
                                t.y += 1;
                                break;
                        case 'k':
                                mvwaddch(game_win, t.y, t.x, ' ');
                                t.y -= 1;
                                break;
                        case 'l':
                                mvwaddch(game_win, t.y, t.x, ' ');
                                t.x += 1;
                                break;
                        }

                        turtle_draw(&t, game_win);
                        /* turtle_stats_draw(&t, stats_win); */

                        window_update(game_win);
                        /* win_draw(stats_win); */
                }
                break;
        }

        endwin();
        return EXIT_SUCCESS;
}
