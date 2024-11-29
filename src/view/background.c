#include <stdio.h>

#include "view/background.h"
#include "view/utils.h"

void draw_background()
{
	Dimension size;
	get_window_size(&size);

	set_cursor_pos(1, 1);
	printf("╔");
	set_cursor_pos(size.width, 1);
	printf("╗");
	set_cursor_pos(1, size.height);
	printf("╚");
	set_cursor_pos(size.width, size.height);
	printf("╝");

	for(int i = 2; i < size.width; i++)
	{
		set_cursor_pos(i, 1);
		printf("═");
	}

	for (int i = 2; i < size.width; i++)
	{
		set_cursor_pos(i, size.height);
		printf("═");
	}

	for (int i = 2; i < size.height; i++)
	{
		set_cursor_pos(1, i);
		printf("║");
	}

	for (int i = 2; i < size.height; i++)
	{
		set_cursor_pos(size.width, i);
		printf("║");
	}
}
