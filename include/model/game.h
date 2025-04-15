//
// Created by M Lunkeit on 16.04.25.
//

#ifndef GAME_H
#define GAME_H

#include "model/snake.h"
#include "model/apple.h"
#include "view/utils.h"

typedef struct Game
{
  Snake *snake;
  Dimension *size;
  Apple *apple;
} Game;

void game_init(Game *game, Dimension *size);

void game_tick(Game *game);

char game_over(Game *game);

#endif //GAME_H
