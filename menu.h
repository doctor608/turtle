#ifndef MENU_H
#define MENU_H

#include <ncurses.h>

typedef enum {
    MENU_PLAY, MENU_SETTINGS, MENU_EXIT,
} MenuChoice;

extern WINDOW* menu_win;

void menu_init();
MenuChoice menu_mainloop();

#endif
