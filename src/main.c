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

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <controller/keys.h>

#include "view/painter.h"

void *begin_painter_loop()
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = 200000000;

  nanosleep(&ts, NULL);

  while (1)
  {
    painter_loop();
    nanosleep(&ts, NULL);
  }
}

void *listen_for_input()
{
  start_listening(painter_handle_button);
  return 0;
}

int main()
{
  srand(time(NULL));

  painter_init();

  pthread_t thread[2];

  pthread_create(&thread[0], NULL, begin_painter_loop, NULL);
  pthread_create(&thread[1], NULL, listen_for_input, NULL);

  pthread_join(thread[0], NULL);
  pthread_join(thread[1], NULL);

	return 0;
}
