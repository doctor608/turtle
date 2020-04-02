#ifndef COLOR_H
#define COLOR_H

typedef enum {
        RED_BLACK = 1,
        GREEN_BLACK,
        BLUE_BLACK,
        CYAN_BLACK,
        YELLOW_BLACK,
        MAGENTA_BLACK,
        WHITE_BLACK,
} Color;

/* Initialize color pairs. */
void color_init();

#endif  // COLOR_H
