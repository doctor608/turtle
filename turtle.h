#ifndef TURTLE_H
#define TURTLE_H

#include <ncurses.h>

#define TURTLE_COLOR 1

typedef struct {
        char body;
        int x;
        int y;
} Turtle;

void turtle_init(Turtle* t, char body);
void turtle_update(Turtle* t, WINDOW* w);
void turtle_draw(const Turtle* t, WINDOW* w);
void turtle_stats_draw(const Turtle* t, WINDOW* w);

#endif
