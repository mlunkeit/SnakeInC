/*
* This file is part of Snake.
 *
 * Copyright (C) 2025 Malte Lunkeit
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <https://www.gnu.org/licenses/>.
 */

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
Dimension game_dimension;

void paint_snake_tile(const int x, const int y)
{
    set_cursor_pos(2*x-1, y);
    printf("  ");
}

void paint_apple(Apple *apple)
{
    set_cursor_pos(apple->x*2-1, apple->y);
    printf("  ");
}

void painter_init()
{
    get_window_size(&dimension);
    game_dimension = dimension;
    game_dimension.width = dimension.width/2;

    game_init(&game, &game_dimension);

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

    set_text_color(BG_RED);
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