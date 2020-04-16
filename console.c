#include "console.h"

#include "window.h"

#include <ncurses.h>

#define PROMPT ">>> "
#define PROMPT_LEN 4
#define MAX_CONSOLE_INPUT 64

WINDOW* console_win = NULL;

void console_init()
{
        console_win = newwin(CONSOLE_WIN_HEIGHT, CONSOLE_WIN_WIDTH, GAME_WIN_HEIGHT, COLS / 2);
}

void console_prompt_draw(WINDOW* w)
{
        mvwprintw(w, 1, 2, PROMPT);
}
