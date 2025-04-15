//
// Created by malte on 29.11.24.
//

#ifndef MODEL_SNAKE_H
#define MODEL_SNAKE_H

#include "enums.h"
#include "view/utils.h"

typedef struct SnakeNode
{
  int x;
  int y;

  struct SnakeNode *next;
  struct SnakeNode *prev;
} SnakeNode;

typedef struct Snake
{
  SnakeNode *beforeCurrent;

  SnakeNode *head;
  SnakeNode *last;

  Direction direction;
} Snake;

/**
 * Initializes the snake at the given position
 *
 * @param snake a pointer to the snake to initialize
 * @param x the x coordinate
 * @param y the y coordinate
 */
void snake_init(Snake *snake, int x, int y);

/**
 * Iterates through all snake nodes starting at the head
 *
 * @param snake a pointer to the snake to iterate through
 * @param iterate an iterator function that takes the coordinates of the SnakeNode
 */
void snake_iterate(const Snake *snake, void (*iterate)(int, int));

void snake_move(Snake *snake);

void snake_append(Snake *snake);

char snake_contains(const Snake *snake, int x, int y);

char snake_lost(const Snake *snake, const Dimension *size);

void snake_clear(const Snake *snake);

#endif //MODEL_SNAKE_H
