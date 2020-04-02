#ifndef TURTLE_H
#define TURTLE_H

typedef struct {
        char body;
        int cur_x;
        int cur_y;
        int prev_x;
        int prev_y;
} Turtle;

typedef enum {
        LEFT, RIGHT, UP, DOWN
} Direction;

void turtle_init(Turtle* t);
void turtle_draw(const Turtle* t);
void turtle_move(Turtle* t, Direction dir);

#endif  // TURTLE_H
