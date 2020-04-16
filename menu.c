#include "menu.h"

#include <ncurses.h>

#include <string.h>

WINDOW* menu_win = NULL;

#define MENU_WIDTH 20
#define MENU_HEIGHT MENU_CHOICES_NUM + 2
#define MENU_CHOICES_NUM 3
#define MENU_X COLS / 2 - MENU_WIDTH / 2
#define MENU_Y LINES / 2

static int indent_count(int width, const char* s);

void menu_init()
{
        menu_win = newwin(MENU_HEIGHT, MENU_WIDTH, MENU_Y, MENU_X);
}

MenuChoice menu_mainloop()
{
        int choice;
        int highlight = 0;
        const char* menu_choices[MENU_CHOICES_NUM] = { "play", "settings", "exit" };

        mvprintw(MENU_Y - 1, MENU_X + indent_count(MENU_WIDTH, "MENU"), "MENU");
        refresh();

        while (1) {
                box(menu_win, 0, 0);
                wrefresh(menu_win);

                for (int i = 0; i < MENU_CHOICES_NUM; ++i) {
                        if (i == highlight)
                                wattron(menu_win, A_REVERSE);
                        mvwprintw(menu_win, i + 1, indent_count(MENU_WIDTH, menu_choices[i]),
                                  menu_choices[i]);
                        wattroff(menu_win, A_REVERSE);
                }
                wrefresh(menu_win);

                choice = wgetch(menu_win);
                switch (choice) {
                case 'j':
                        highlight++;
                        if (highlight >= MENU_CHOICES_NUM)
                                highlight = MENU_CHOICES_NUM - 1;
                        break;
                case 'k':
                        highlight--;
                        if (highlight < 0)
                                highlight = 0;
                        break;
                }

                if (choice == ' ')
                        break;
        }

        return (MenuChoice) highlight;
}

static int indent_count(int width, const char* s)
{
        return (width - strlen(s)) / 2;
}
