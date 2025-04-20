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

#include "view/background.h"
#include "view/utils.h"

void draw_background(Dimension* size)
{
	set_cursor_pos(1, 1);
	printf("╔");
	set_cursor_pos(size->width, 1);
	printf("╗");
	set_cursor_pos(1, size->height);
	printf("╚");
	set_cursor_pos(size->width, size->height);
	printf("╝");

	for(int i = 2; i < size->width; i++)
	{
		set_cursor_pos(i, 1);
		printf("═");
	}

	for (int i = 2; i < size->width; i++)
	{
		set_cursor_pos(i, size->height);
		printf("═");
	}

	for (int i = 2; i < size->height; i++)
	{
		set_cursor_pos(1, i);
		printf("║");
	}

	for (int i = 2; i < size->height; i++)
	{
		set_cursor_pos(size->width, i);
		printf("║");
	}
}
