#ifndef TURTLE_H
#define TURTLE_H

#include <ncurses.h>

#define TURTLE_COLOR 1

typedef struct {
        int x;
        int y;
        char body[5][5];
} Turtle;

void turtle_init(Turtle* t);
void turtle_update(Turtle* t, WINDOW* w, int ch);
void turtle_draw(const Turtle* t, WINDOW* w);
/* void turtle_stats_draw(const Turtle* t, WINDOW* w); */

#endif
