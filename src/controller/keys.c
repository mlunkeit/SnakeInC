#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#include "enums.h"
#include "controller/keys.h"

void set_terminal_mode() {
    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &new_settings);
    new_settings.c_lflag &= ~(ICANON | ECHO);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

void reset_terminal_mode() {
    struct termios new_settings;
    tcgetattr(STDIN_FILENO, &new_settings);
    new_settings.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSANOW, &new_settings);
}

void start_listening(void (*callback)(Direction))
{
  int ch;
  set_terminal_mode();
  
  while(1)
  {
    ch = getchar();
    if(ch == 27)
    {
      ch = getchar();
      
      if(ch == '[')
      {
        ch = getchar();
        
        switch(ch)
        {
          case 'A':
            callback(NORTH);
            break;
          
          case 'B':
            callback(SOUTH);
            break;
          
          case 'C':
            callback(EAST);
            break;
          
          case 'D':
            callback(WEST);
            break;

          default: break;
        }
      }
    }
  }
}
