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

#include "model/snake.h"

#include <stdlib.h>

void snake_init(Snake *snake, const int x, const int y)
{
  snake->head = malloc(sizeof(SnakeNode));
  snake->head->x = x;
  snake->head->y = y;

  snake->last = malloc(sizeof(SnakeNode));
  snake->last->x = x - 1;
  snake->last->y = y;

  snake->head->next = snake->last;
  snake->head->prev = NULL;
  snake->last->next = NULL;
  snake->last->prev = snake->head;

  snake->direction = EAST;
}

void snake_iterate(const Snake *snake, void (*iterate)(int, int))
{
  const SnakeNode *current = snake->head;
  while (current != NULL)
  {
    iterate(current->x, current->y);
    current = current->next;
  }
}

void snake_move(Snake *snake)
{
  const int dir = snake->direction;
  const char hasMinus = (dir / 2) % 2 == 0;

  const int delta_x = (dir % 2) * (hasMinus ? 1 : -1);
  const int delta_y = (1 - dir % 2) * (!hasMinus ? 1 : -1);

  SnakeNode *newHead = snake->last;

  newHead->x = snake->head->x + delta_x;
  newHead->y = snake->head->y + delta_y;

  snake->last = newHead->prev;
  snake->last->next = NULL;

  newHead->next = snake->head;
  newHead->prev = NULL;

  snake->head->prev = newHead;

  snake->head = newHead;
}

void snake_append(Snake *snake)
{
  const int dir = snake->direction;
  const char hasMinus = (dir / 2) % 2 == 0;

  const int delta_x = (dir % 2) * (hasMinus ? 1 : -1);
  const int delta_y = (1 - dir % 2) * (!hasMinus ? 1 : -1);

  SnakeNode *newHead = malloc(sizeof(SnakeNode));

  newHead->x = snake->head->x + delta_x;
  newHead->y = snake->head->y + delta_y;

  newHead->next = snake->head;
  newHead->prev = NULL;

  snake->head->prev = newHead;
  snake->head = newHead;
}

bool snake_contains(const Snake *snake, int x, int y)
{
  SnakeNode *current = snake->head->next;

  while (current != NULL)
  {
    if (current->x == x && current->y == y)
      return true;
    current = current->next;
  }

  return false;
}

bool snake_lost(const Snake *snake, const Dimension *size)
{
  return snake_contains(snake, snake->head->x, snake->head->y) ||
    snake->head->x <= 1 || snake->head->y <= 1 ||
      snake->head->x >= size->width || snake->head->y >= size->height;
}

void snake_free(const Snake *snake)
{
  SnakeNode *current = snake->head;
  while (current != NULL)
  {
    SnakeNode *next = current->next;
    free(current);
    current = next;
  }
}