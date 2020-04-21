#include "window.h"

#include <ncurses.h>

void window_update(WINDOW* w)
{
        box(w, 0, 0);
        wrefresh(w);
}
