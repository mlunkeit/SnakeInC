#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <controller/keys.h>

#include "enums.h"

#include "view/utils.h"
#include "view/background.h"
#include "view/painter.h"

void *begin_painter_loop()
{
  struct timespec ts;
  ts.tv_sec = 0;
  ts.tv_nsec = 100000000;

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
