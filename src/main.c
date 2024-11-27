#include <stdio.h>

#include "enums.h"
#include "controller/keys.h"

#define clear() printf("\033[H\033[J")
#define setCursorPos(x,y) printf("\033[%d;%dH", (y), (x))

void onInput(Direction direction)
{
  clear();
  
  setCursorPos(5, 5);

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
  
  setCursorPos(1, 1);
}

int main()
{
	clear();
	startListening(onInput);
	return 0;
}
