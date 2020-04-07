#include "window.h"

#include <ncurses.h>

void window_init(Window* w, int width, int height, int startx, int starty)
{
        w->width = width;
        w->height = height;
        w->startx = startx;
        w->starty = starty;
        w->surface = newwin(height, width, starty, startx);
        box(w->surface, 0, 0);
}
