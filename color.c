#include "color.h"

#include <ncurses.h>

void color_init()
{
        start_color();
        init_pair(RED_BLACK, COLOR_RED, COLOR_BLACK);
        init_pair(GREEN_BLACK, COLOR_GREEN, COLOR_BLACK);
        init_pair(BLUE_BLACK, COLOR_BLUE, COLOR_BLACK);
        init_pair(CYAN_BLACK, COLOR_CYAN, COLOR_BLACK);
        init_pair(YELLOW_BLACK, COLOR_YELLOW, COLOR_BLACK);
        init_pair(MAGENTA_BLACK, COLOR_MAGENTA, COLOR_BLACK);
        init_pair(WHITE_BLACK, COLOR_WHITE, COLOR_BLACK);
}
