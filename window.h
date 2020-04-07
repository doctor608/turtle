#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

#define GAME_WIN_WIDTH  COLS
#define GAME_WIN_HEIGHT LINES - LINES / 4

#define STATS_WIN_WIDTH COLS
#define STATS_WIN_HEIGHT LINES / 4

typedef struct {
        int width;
        int height;
        int startx;
        int starty;
        WINDOW* surface;
} Window;

void window_init(Window* w, int width, int height, int startx, int starty);
#endif
