#ifndef TURTLE_H
#define TURTLE_H

typedef struct {
        char body;
        int cur_x;
        int cur_y;
        int prev_x;
        int prev_y;
} Turtle;

void turtle_init(Turtle* t);
void turtle_draw(const Turtle* t);

#endif  // TURTLE_H
