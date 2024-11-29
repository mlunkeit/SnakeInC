#ifndef MODEL_UTILS_H
#define MODEL_UTILS_H

#define TEXT_RED "\033[31m"
#define TEXT_GREEN "\033[32m"
#define TEXT_YELLOW "\033[33m"
#define TEXT_BLUE "\033[34m"
#define TEXT_MAGENTA "\033[35m"
#define TEXT_CYAN "\033[36m"
#define TEXT_WHITE "\033[37m"

typedef struct Dimension
{
	int width;
	int height;
} Dimension;

void get_window_size(Dimension* dimension);

void clear_screen();

void set_cursor_pos(int x, int y);

void set_text_color(const char* color);

void reset_text_color();

#endif
