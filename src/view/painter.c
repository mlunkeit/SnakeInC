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
    printf(" ");
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

    clear_screen();
    draw_background(&dimension);
}

void painter_loop()
{
    set_text_color(STYLE_RESET);

    paint_snake_tile(game.snake->last->x, game.snake->last->y);

    game_tick(&game);

    set_text_color(TEXT_WHITE);

    set_cursor_pos(3,1);

    set_text_color(TEXT_BRIGHT_WHITE);
    set_text_color(STYLE_BOLD);

    printf(" Score: %d ", game.score);

    set_text_color(STYLE_RESET);

    set_text_color(BG_BRIGHT_GREEN);
    snake_iterate(game.snake, paint_snake_tile);

    set_text_color(BG_GREEN);
    paint_snake_tile(game.snake->head->x, game.snake->head->y);

    set_text_color(STYLE_RESET);

    set_text_color(STYLE_BOLD);
    set_text_color(TEXT_RED);
    paint_apple(game.apple);

    set_text_color(STYLE_RESET);

    set_cursor_pos(1,1);

    if (game_over(&game))
        exit(0);
}

void painter_handle_button(const Direction dir)
{
    if (game.snake->direction % 2 != dir % 2)
        game.snake->direction = dir;
}