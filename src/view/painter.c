#include <stdio.h>
#include <stdlib.h>

#include "view/background.h"
#include "view/utils.h"
#include "view/painter.h"
#include "model/snake.h"
#include "enums.h"

Direction direction = EAST;
Snake snake;

void paint_snake_tile(const int x, const int y)
{
    set_cursor_pos(x, y);
    printf("#");

    set_cursor_pos(1,1);
}

void painter_init()
{
    Dimension size;
    get_window_size(&size);

    snake_init(&snake, size.width/2, size.height/2);
}

void painter_loop()
{
    snake_append(&snake, &direction);

    clear_screen();

    set_text_color(TEXT_WHITE);
    draw_background();

    set_text_color(TEXT_RED);
    snake_iterate(&snake, paint_snake_tile);

    if (snake_lost(&snake))
        exit(0);
}

void painter_handle_button(const Direction dir)
{
    direction = dir;
}