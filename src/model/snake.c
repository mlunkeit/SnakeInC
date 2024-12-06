//
// Created by malte on 29.11.24.
//

#include "model/snake.h"

void snake_init(Snake *snake)
{
  SnakeNode head;
  head.x = -1;
  head.y = -1;
  snake->head = &head;

  SnakeNode last;
  last.x = -1;
  last.y = -1;
  snake->last = &last;
}

