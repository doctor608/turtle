#include "turtle.h"

#include "window.h"

#include <ncurses.h>

static void turtle_handle_border_collision(Turtle* t);

void turtle_init(Turtle* t, char body)
{
        t->body = body;
        t->x = COLS / 2;
        t->y = LINES / 2;
        init_pair(TURTLE_COLOR, COLOR_GREEN, COLOR_BLACK);
}

void turtle_draw(const Turtle* t, WINDOW* w)
{
        wattron(w, COLOR_PAIR(TURTLE_COLOR));
        mvwaddch(w, t->y, t->x, t->body);
        wattroff(w, COLOR_PAIR(TURTLE_COLOR));
}

void turtle_stats_draw(const Turtle* t, WINDOW* w)
{
        mvwprintw(w, 1, 2, "x: %i\n", t->x);
        mvwprintw(w, 2, 2, "y: %i\n", t->y);
}

void turtle_update(Turtle* t, WINDOW* w)
{
        int ch = getch();
        switch (ch) {
        case 'h':
                mvwaddch(w, t->y, t->x, ' ');
                t->x -= 1;
                break;
        case 'j':
                mvwaddch(w, t->y, t->x, ' ');
                t->y += 1;
                break;
        case 'k':
                mvwaddch(w, t->y, t->x, ' ');
                t->y -= 1;
                break;
        case 'l':
                mvwaddch(w, t->y, t->x, ' ');
                t->x += 1;
                break;
        }
        turtle_handle_border_collision(t);
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
