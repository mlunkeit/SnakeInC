#include <stdio.h>

#include "enums.h"
#include "controller/keys.h"

#include "view/utils.h"
#include "view/background.h"

void onInput(const Direction direction)
{
  clear_screen();
  
  set_cursor_pos(5, 5);

  set_text_color(TEXT_RED);

  switch(direction)
  {
    case NORTH:
      printf("Oben");
      break;
      
    case EAST:
      printf("Rechts");
      break;
      
    case SOUTH:
      printf("Unten");
      break;
      
    case WEST:
      printf("Links");
      break;
  }
  
  set_cursor_pos(1, 1);
}

int main()
{
	clear_screen();
	draw_background();
	startListening(onInput);
	return 0;
}
