//
// Created by M Lunkeit on 16.04.25.
//

#include "model/game.h"
#include "model/apple.h"
#include "model/snake.h"

#include <stdlib.h>

void game_init(Game *game, Dimension *size)
{
    Snake *snake = malloc(sizeof(Snake));
    game->snake = snake;

    Apple *apple = malloc(sizeof(Apple));
    apple->x = rand() % (size->width - 2) + 1;
    apple->y = rand() % (size->height - 2) + 1;
    game->apple = apple;

    snake_init(snake, size->width/2, size->height/2);
}

void game_tick(Game *game)
{
    if (game->snake->head->x == game->apple->x && game->snake->head->y == game->apple->y)
    {
        snake_append(game->snake);

        game->apple->x = rand() % (game->size->width - 2) + 1;
        game->apple->y = rand() % (game->size->height - 2) + 1;
    }
    else
    {
        snake_move(game->snake);
    }
}