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