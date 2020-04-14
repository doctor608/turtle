#include "turtle.h"
#include "window.h"
#include "console.h"

#include <ncurses.h>

#include <stdlib.h>
#include <string.h>

int main(void)
{
        /* Don't touch us! */
        initscr();
        cbreak();
        keypad(stdscr, TRUE);
        noecho();
        curs_set(0);
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
                /* turtle_update(&t, game_win); */
                /* process_events(); */

                int ch = getch();
                char console_input[64];
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
                case ':':
                        echo();
                        mvwgetnstr(console_win, 1, 6, console_input, 64);
                        noecho();

                        wmove(console_win, 2, 2);
                        for (int i = 0; i < CONSOLE_WIN_WIDTH - 6; ++i)
                                waddch(console_win, '\b');
                        wmove(console_win, 2, 2);
                        for (int i = 0; i < CONSOLE_WIN_WIDTH - 6; ++i)
                                waddch(console_win, ' ');

                        for (int i = 0; i < strlen(console_input); ++i)
                                waddch(console_win, console_input[i]);

                        wmove(console_win, 1, 6);
                        for (int i = 0; i < CONSOLE_WIN_WIDTH - 6; ++i)
                                waddch(console_win, '\b');
                        wmove(console_win, 1, 6);
                        for (int i = 0; i < CONSOLE_WIN_WIDTH - 6; ++i)
                                waddch(console_win, ' ');
                }

                turtle_draw(&t, game_win);
                console_prompt_draw(console_win);
                turtle_stats_draw(&t, stats_win);

                win_draw(game_win);
                win_draw(stats_win);
                win_draw(console_win);
        }

        endwin();
        return EXIT_SUCCESS;
}
