#ifndef WINDOW_H
#define WINDOW_H

#include <ncurses.h>

#define GAME_WIN_WIDTH  COLS
#define GAME_WIN_HEIGHT LINES - LINES / 4

#define STATS_WIN_WIDTH  COLS / 2
#define STATS_WIN_HEIGHT LINES / 4

#define CONSOLE_WIN_WIDTH  COLS / 2
#define CONSOLE_WIN_HEIGHT LINES / 4

void win_draw(WINDOW* w);

#endif
