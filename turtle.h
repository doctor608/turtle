#ifndef TURTLE_H
#define TURTLE_H

#include "color.h"

typedef enum {
        LEFT, RIGHT, UP, DOWN
} Direction;

typedef struct {
        // Appearance
        char body;
        Color color;
        // Position
        int cur_x;
        int cur_y;
        int prev_x;
        int prev_y;
} Turtle;

void turtle_init(Turtle* t, char body, Color c);
void turtle_draw(const Turtle* t);
void turtle_move(Turtle* t, Direction dir);
void turtle_update(Turtle* t);

#endif  // TURTLE_H
