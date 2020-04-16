#ifndef CONSOLE_H
#define CONSOLE_H

#include <ncurses.h>

#define CONSOLE_WIN_WIDTH  COLS / 2
#define CONSOLE_WIN_HEIGHT LINES / 4

extern WINDOW* console_win;

void console_init();
void console_prompt_draw(WINDOW* w);

#endif
