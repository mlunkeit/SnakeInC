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

#include "view/utils.h"

#include <stdio.h>
#include <sys/ioctl.h>
#include <unistd.h>

void get_window_size(Dimension* dimension)
{
	struct winsize ws;

	if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1)
	{
		perror("ioctl");

		dimension->width = -1;
		dimension->height= -1;
	}
	else
	{
		dimension->width = ws.ws_col;
		dimension->height = ws.ws_row;
	}
}

void clear_screen()
{
	printf("\033[H\033[J");
}

void set_cursor_pos(int x, int y)
{
	printf("\033[%d;%dH", y, x);
	fflush(stdout);
}

void set_text_color(const char* color)
{
	printf("%s", color);
	fflush(stdout);
}

void reset_text_color()
{
	set_text_color("\033[0m");
}