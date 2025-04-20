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

#include "model/game.h"
#include "model/apple.h"
#include "model/snake.h"

#include <stdlib.h>

void place_apple_randomly(Game *game)
{
    do
    {
        game->apple->x = rand() % (game->size->width - 2) + 1;
        game->apple->y = rand() % (game->size->height - 2) + 1;
    }
    while (snake_contains(game->snake, game->apple->x, game->apple->y) ||
        (game->snake->head->x == game->apple->x && game->snake->head->y == game->apple->y) ||
        game->apple->x <= 1 || game->apple->y <= 1 || game->apple->x >= game->size->width || game->apple->y >= game->size->height);
}

void game_init(Game *game, Dimension *size)
{
    game->size = size;

    game->score = 0;

    Snake *snake = malloc(sizeof(Snake));
    game->snake = snake;
    snake_init(snake, size->width/2, size->height/2);

    game->apple = malloc(sizeof(Apple));
    game->apple->x = 0;
    game->apple->y = 0;
    place_apple_randomly(game);
}

void game_tick(Game *game)
{
    if (game->snake->head->x == game->apple->x && game->snake->head->y == game->apple->y)
    {
        snake_append(game->snake);
        place_apple_randomly(game);
        game->score++;
    }
    else
    {
        snake_move(game->snake);
    }
}

bool game_over(Game *game)
{
    return snake_lost(game->snake, game->size);
}

void game_free(Game *game)
{
    snake_free(game->snake);
    free(game->snake);
    free(game->apple);
}