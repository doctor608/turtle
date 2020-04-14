#include "window.h"

#include <ncurses.h>

void win_draw(WINDOW* w)
{
        box(w, 0, 0);
        wrefresh(w);
}
