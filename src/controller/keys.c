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
