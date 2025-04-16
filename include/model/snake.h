//
// Created by malte on 29.11.24.
//

#ifndef MODEL_SNAKE_H
#define MODEL_SNAKE_H

#include <stdbool.h>

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

/**
 * Moves the snake in the direction the snake faces
 *
 * @param snake a pointer to the snake to move
 */
void snake_move(Snake *snake);

/**
 * Moves the snake in the direction the snake faces and appends a new tile to the snake.
 *
 * @param snake
 */
void snake_append(Snake *snake);

/**
 * Checks if the snake has a tile at the given coordinates. This does not include the head of the snake.
 *
 * @param snake a pointer to the snake
 * @param x the x coordinate
 * @param y the y coordinate
 * @return if the snake contains the given coordinates
 */
bool snake_contains(const Snake *snake, int x, int y);

/**
 * Checks if the snake is dead.
 *
 * @param snake a pointer to the snake
 * @param size the game area
 * @return if the snake is dead
 */
bool snake_lost(const Snake *snake, const Dimension *size);

/**
 * Frees all allocated memory used by the snake
 *
 * @param snake a pointer to the snake
 */
void snake_free(const Snake *snake);

#endif //MODEL_SNAKE_H
