#include <stdio.h>
#include <stdlib.h>

#include "view/background.h"
#include "view/utils.h"
#include "view/painter.h"
#include "model/snake.h"
#include "enums.h"

Dimension dimension;
Snake snake;

void paint_snake_tile(const int x, const int y)
{
    set_cursor_pos(x, y);
    printf("#");

    set_cursor_pos(1,1);
}

void painter_init()
{
    get_window_size(&dimension);

    snake_init(&snake, dimension.width/2, dimension.height/2);
}

void painter_loop()
{
    snake_append(&snake);

    clear_screen();

    set_text_color(TEXT_WHITE);
    draw_background(&dimension);

    set_text_color(TEXT_GREEN);
    snake_iterate(&snake, paint_snake_tile);

    if (snake_lost(&snake, &dimension))
        exit(0);
}

void painter_handle_button(const Direction dir)
{
    snake.direction = dir;
}