#include "turtle.h"

#include <ncurses.h>

#include <stdio.h>
#include <stdlib.h>

#define OCEAN_COLOR_PAIR 1
#define BEACH_COLOR_PAIR 2
#define TURTLE_COLOR_PAIR 3

void init_colors();
void init_color_pairs();
void draw_background();

int main(void)
{
        initscr();  // <-- Initialize ncurses.

        start_color(); // <-- Enable colors
        init_colors();
        init_color_pairs();
        noecho();  // <-- Do not print on the screen.

        Turtle t;
        turtle_init(&t);  // <- Create a Turtle

        int ch;
        for (;;) {
                /* draw_background(); */

                if ((ch = getch()) != ERR) {
                        switch (ch) {
                        case 'h':
                                t.prev_x = t.cur_x;
                                --t.cur_x;
                                break;
                        case 'j':
                                t.prev_y = t.cur_y;
                                ++t.cur_y;
                                break;
                        case 'k':
                                t.prev_y = t.cur_y;
                                --t.cur_y;
                                break;
                        case 'l':
                                t.prev_x = t.cur_x;
                                ++t.cur_x;
                                break;
                        }
                }

                turtle_draw(&t);
                refresh();  // <-- Clear window
        }

        endwin();  // <-- Restore terminal settings.

        return EXIT_SUCCESS;
}

void init_colors()
{
        init_color(COLOR_RED, 1000, 686, 0);  // <-- Orange1
}

void init_color_pairs()
{

        init_pair(OCEAN_COLOR_PAIR, COLOR_BLACK, COLOR_BLUE);
        init_pair(BEACH_COLOR_PAIR, COLOR_BLACK, COLOR_RED);
        init_pair(TURTLE_COLOR_PAIR, COLOR_BLACK, COLOR_GREEN);
}

void draw_background()
{
        // Draw up beach
        for (int i = 0; i < COLS; ++i) {
                attron(COLOR_PAIR(BEACH_COLOR_PAIR));
                addch(' ');
                attroff(COLOR_PAIR(BEACH_COLOR_PAIR));
        }
        // Draw ocean
        for (int i = 0; i < LINES - 2; ++i) {
                // Draw left beach
                attron(COLOR_PAIR(BEACH_COLOR_PAIR));
                printw("  ");
                attroff(COLOR_PAIR(BEACH_COLOR_PAIR));
                // Draw middle ocean
                attron(COLOR_PAIR(OCEAN_COLOR_PAIR));
                for (int j = 0; j < COLS - 4; ++j)
                        addch(' ');
                attroff(COLOR_PAIR(OCEAN_COLOR_PAIR));
                // Draw right beach
                attron(COLOR_PAIR(BEACH_COLOR_PAIR));
                printw("  ");
                attroff(COLOR_PAIR(BEACH_COLOR_PAIR));
        }
        // Draw down beach
        for (int i = 0; i < COLS; ++i) {
                attron(COLOR_PAIR(BEACH_COLOR_PAIR));
                addch(' ');
                attroff(COLOR_PAIR(BEACH_COLOR_PAIR));
        }
        addch('\n');
}
