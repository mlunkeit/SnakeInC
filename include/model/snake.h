//
// Created by malte on 29.11.24.
//

#ifndef MODEL_SNAKE_H
#define MODEL_SNAKE_H

#include "enums.h"

typedef struct SnakeNode
{
  int x;
  int y;

  struct SnakeNode *next;
} SnakeNode;

typedef struct Snake
{
  int length;

  SnakeNode *beforeCurrent;

  SnakeNode *head;
  SnakeNode *last;
} Snake;

void snake_init(Snake *snake);

void snake_iterate(Snake *snake, void (*iterate)(int, int));

void snake_move(Snake *snake, Direction *direction);

void snake_append(Snake *snake, Direction *direction);

char snake_contains(Snake *snake, int x, int y);

char snake_lost(Snake *snake);

#endif //MODEL_SNAKE_H
