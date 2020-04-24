#ifndef TURTLE_H
#define TURTLE_H

#include <ncurses.h>

typedef struct {
        int x;
        int y;
        int width;
        int height;
        int color;
        char** body;
} Turtle;

void turtle_init(Turtle* t, const char* skin_filename);
void turtle_del(Turtle* t);
void turtle_draw(const Turtle* t);
void turtle_update(Turtle* t, int ch);

#endif
