#include "turtle.h"

#include "window.h"

#include <ncurses.h>

#include <string.h>

static void turtle_handle_border_collision(Turtle* t);

void turtle_init(Turtle* t)
{
        t->x = COLS / 2 - 3;
        t->y = GAME_WIN_HEIGHT - 5;
        char skin[5][5] = {
                {' ', ' ', 'O', ' ', ' ',},
                {'<', '#', '#', '#', '>' },
                {'(', '#', '#', '#', ')' },
                {'<', '#', '#', '#', '>' },
                {' ', ' ', 'V', ' ', ' ' },
        };
        for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                        t->body[i][j] = skin[i][j];
                }
        }
        init_pair(TURTLE_COLOR, COLOR_GREEN, COLOR_BLACK);
}

void turtle_draw(const Turtle* t, WINDOW* w)
{
        wattron(w, COLOR_PAIR(TURTLE_COLOR));
        for (int i = 0; i < 5; ++i) {
                for (int j = 0; j < 5; ++j) {
                        mvwaddch(w, t->y + i, t->x + j, t->body[i][j]);
                }
        }
        wattroff(w, COLOR_PAIR(TURTLE_COLOR));

}

void turtle_update(Turtle* t, WINDOW* w, int ch)
{
        switch (ch) {
        case 'h':
                for (int i = 0; i < 5; ++i) {
                        for (int j = 0; j < 5; ++j) {
                                mvwaddch(w, t->y + i, t->x + j, ' ');
                        }
                }
                t->x -= 1;
                break;
        case 'j':
                for (int i = 0; i < 5; ++i) {
                        for (int j = 0; j < 5; ++j) {
                                mvwaddch(w, t->y + i, t->x + j, ' ');
                        }
                }
                t->y += 1;
                break;
        case 'k':
                for (int i = 0; i < 5; ++i) {
                        for (int j = 0; j < 5; ++j) {
                                mvwaddch(w, t->y + i, t->x + j, ' ');
                        }
                }
                t->y -= 1;
                break;
        case 'l':
                for (int i = 0; i < 5; ++i) {
                        for (int j = 0; j < 5; ++j) {
                                mvwaddch(w, t->y + i, t->x + j, ' ');
                        }
                }
                t->x += 1;
                break;
        }
        /* turtle_handle_border_collision(t); */
}

static void turtle_handle_border_collision(Turtle* t)
{
        // All minuses because of windows' borders
        if (t->x >= GAME_WIN_WIDTH - 1)
                t->x = GAME_WIN_WIDTH - 2;
        else if (t->x <= 0)
                t->x = 1;
        else if (t->y >= GAME_WIN_HEIGHT - 1)
                t->y = GAME_WIN_HEIGHT - 2;
        else if (t->y <= 0)
                t->y = 1;
}
