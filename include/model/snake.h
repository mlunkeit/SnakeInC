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
  struct SnakeNode *prev;
} SnakeNode;

typedef struct Snake
{
  int length;

  SnakeNode *beforeCurrent;

  SnakeNode *head;
  SnakeNode *last;
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

void snake_move(Snake *snake, const Direction *direction);

void snake_append(Snake *snake, const Direction *direction);

char snake_contains(Snake *snake, int x, int y);

char snake_lost(const Snake *snake);

void snake_clear(const Snake *snake);

#endif //MODEL_SNAKE_H
