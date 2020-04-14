#include "console.h"

#include "window.h"

#include <ncurses.h>

#define PROMPT ">>> "
#define PROMPT_LEN 4
#define MAX_CONSOLE_INPUT 64

void console_prompt_draw(WINDOW* w)
{
        mvwprintw(w, 1, 2, PROMPT);
}
