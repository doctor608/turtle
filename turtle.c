#include "turtle.h"

#include <ncurses.h>

void turtle_init(Turtle* t)
{
        t->body = '&';
        t->cur_x  = COLS / 2;
        t->prev_x = COLS / 2;
        t->cur_y  = LINES / 2;
        t->prev_y = LINES / 2;
}

void turtle_draw(const Turtle* t)
{
        /* attron(COLOR_PAIR(TURTLE_COLOR_PAIR)); */
        printw("prev_x - %d, prev_y %d, cur_x - %d, cur_y - %d\n", 
                        t->prev_x, t->prev_y, t->cur_x, t->cur_y);
        mvdelch(t->prev_y, t->prev_x);
        mvaddch(t->cur_y, t->cur_x, t->body);
        /* attroff(COLOR_PAIR(TURTLE_COLOR_PAIR)); */
}
