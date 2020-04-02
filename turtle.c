#include "turtle.h"

#include <ncurses.h>

void turtle_init(Turtle* t, char body, Color c)
{
        t->body   = body;;
        t->color  = c;
        t->cur_x  = COLS / 2;  // <-- COLS and LINES from ncurses.h
        t->prev_x = COLS / 2;
        t->cur_y  = LINES / 2;
        t->prev_y = LINES / 2;
}

void turtle_draw(const Turtle* t)
{
        attron(COLOR_PAIR(t->color));
		mvdelch(t->prev_y, t->prev_x);
		mvaddch(t->cur_y, t->cur_x, t->body);
        attroff(COLOR_PAIR(t->color));
}

void turtle_move(Turtle* t, Direction dir)
{
        switch (dir) {
        case LEFT:
                t->prev_x = t->cur_x;
                t->prev_y = t->cur_y;
                t->cur_x -= 1;
                break;
        case DOWN:
                t->prev_y = t->cur_y;
                t->prev_x = t->cur_x;
                t->cur_y += 1;
                break;
        case UP:
                t->prev_y = t->cur_y;
                t->prev_x = t->cur_x;
                t->cur_y -= 1;
                break;
        case RIGHT:
                t->prev_x = t->cur_x;
                t->prev_y = t->cur_y;
                t->cur_x += 1;
                break;
        }
}
