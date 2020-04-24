#include "turtle.h"

#include <ncurses.h>

#include <stdlib.h>
#include <string.h>

static void turtle_clear(Turtle* t);
static void turtle_handle_border_collision(Turtle* t);

/* Constructor. */
void turtle_init(Turtle* t, const char* skin_filename, int color)
{
        t->x = COLS / 2 - 3;
        t->y = LINES - 10;
        t->vel = 2;
        t->width = 0;
        t->height = 1;
        t->color = color;

        FILE* skin_file = fopen(skin_filename, "r");
        if (!skin_file) {
                fprintf(stderr, "Error: cannot open file %s.\n", skin_filename);
                exit(EXIT_FAILURE);
        }

        int ch, length = 0;
        char temp_buffer[256];
        while ((ch = fgetc(skin_file)) != EOF) {
                if (ch == '\n') {
                        t->height += 1;
                        continue;
                }
                temp_buffer[length++] = ch;
        }
        t->width = length / t->height;

        t->body = malloc(sizeof(char*) * t->height);
        for (int i = 0; i < t->height; ++i) {
                t->body[i] = malloc(sizeof(char) * t->width);
        }

        int j = 0;
        for (int row = 0; row < t->height; ++row) {
                for (int col = 0; col < t->width; ++col) {
                        t->body[row][col] = temp_buffer[j++];
                }
        }
}

void turtle_del(Turtle* t)
{
        for (int i = 0; i < t->height; ++i) {
                free(t->body[i]);
        }
        free(t->body);
}

void turtle_draw(const Turtle* t)
{
        attron(COLOR_PAIR(t->color));
        for (int i = 0; i < t->height; ++i) {
                for (int j = 0; j < t->width; ++j) {
                        mvaddch(t->y + i, t->x + j, t->body[i][j]);
                }
        }
        attroff(COLOR_PAIR(t->color));
}

static void turtle_clear(Turtle* t)
{
        for (int i = 0; i < t->height; ++i) {
                for (int j = 0; j < t->width; ++j) {
                        mvaddch(t->y + i, t->x + j, ' ');
                }
        }
}

void turtle_update(Turtle* t, int ch)
{
        switch (ch) {
        case 'h':
                turtle_clear(t);
                t->x -= t->vel;
                break;
        case 'j':
                turtle_clear(t);
                t->y += t->vel;
                break;
        case 'k':
                turtle_clear(t);
                t->y -= t->vel;
                break;
        case 'l':
                turtle_clear(t);
                t->x += t->vel;
                break;
        }
        turtle_handle_border_collision(t);
}

static void turtle_handle_border_collision(Turtle* t)
{
        // All minuses because of windows' borders
        if (t->x >= COLS - t->width - 1)
                t->x = COLS - t->width - 1;
        if (t->x <= 0)
                t->x = 1;
        if (t->y >= LINES - t->height - 1)
                t->y = LINES - t->height - 1;
        if (t->y <= 0)
                t->y = 1;
}
