#include <stdio.h>
#include <stdlib.h>

#include "view/background.h"
#include "view/utils.h"
#include "view/painter.h"
#include "model/snake.h"
#include "model/apple.h"
#include "model/game.h"
#include "enums.h"

Game game;
Dimension dimension;

void paint_snake_tile(const int x, const int y)
{
    set_cursor_pos(x, y);
    printf("#");
}

void paint_apple(Apple *apple)
{
    set_cursor_pos(apple->x, apple->y);
    printf("O");
}

void painter_init()
{
    get_window_size(&dimension);

    game_init(&game, &dimension);
}

void painter_loop()
{
    game_tick(&game);

    clear_screen();

    set_text_color(TEXT_WHITE);
    draw_background(&dimension);

    set_text_color(TEXT_GREEN);
    snake_iterate(game.snake, paint_snake_tile);

    set_text_color(TEXT_RED);
    paint_apple(game.apple);

    set_cursor_pos(1,1);

    if (game_over(&game))
        exit(0);
}

void painter_handle_button(const Direction dir)
{
    game.snake->direction = dir;
}