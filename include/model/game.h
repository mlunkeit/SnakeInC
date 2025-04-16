//
// Created by M Lunkeit on 16.04.25.
//

#ifndef GAME_H
#define GAME_H

#include <stdbool.h>

#include "model/snake.h"
#include "model/apple.h"
#include "view/utils.h"

typedef struct Game
{
  Snake *snake;
  Dimension *size;
  Apple *apple;

  int score;
} Game;

void game_init(Game *game, Dimension *size);

void game_tick(Game *game);

bool game_over(Game *game);

void game_free(Game *game);

#endif //GAME_H
