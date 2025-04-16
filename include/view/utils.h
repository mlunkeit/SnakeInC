#ifndef VIEW_UTILS_H
#define VIEW_UTILS_H

// text colors
#define TEXT_BLACK     "\033[30m"
#define TEXT_RED       "\033[31m"
#define TEXT_GREEN     "\033[32m"
#define TEXT_YELLOW    "\033[33m"
#define TEXT_BLUE      "\033[34m"
#define TEXT_MAGENTA   "\033[35m"
#define TEXT_CYAN      "\033[36m"
#define TEXT_WHITE     "\033[37m"

// bright text colors
#define TEXT_BRIGHT_BLACK   "\033[90m"
#define TEXT_BRIGHT_RED     "\033[91m"
#define TEXT_BRIGHT_GREEN   "\033[92m"
#define TEXT_BRIGHT_YELLOW  "\033[93m"
#define TEXT_BRIGHT_BLUE    "\033[94m"
#define TEXT_BRIGHT_MAGENTA "\033[95m"
#define TEXT_BRIGHT_CYAN    "\033[96m"
#define TEXT_BRIGHT_WHITE   "\033[97m"

// background colors
#define BG_BLACK     "\033[40m"
#define BG_RED       "\033[41m"
#define BG_GREEN     "\033[42m"
#define BG_YELLOW    "\033[43m"
#define BG_BLUE      "\033[44m"
#define BG_MAGENTA   "\033[45m"
#define BG_CYAN      "\033[46m"
#define BG_WHITE     "\033[47m"

// bright background colors
#define BG_BRIGHT_BLACK   "\033[100m"
#define BG_BRIGHT_RED     "\033[101m"
#define BG_BRIGHT_GREEN   "\033[102m"
#define BG_BRIGHT_YELLOW  "\033[103m"
#define BG_BRIGHT_BLUE    "\033[104m"
#define BG_BRIGHT_MAGENTA "\033[105m"
#define BG_BRIGHT_CYAN    "\033[106m"
#define BG_BRIGHT_WHITE   "\033[107m"

// formats
#define STYLE_RESET      "\033[0m"
#define STYLE_BOLD       "\033[1m"
#define STYLE_DIM        "\033[2m"
#define STYLE_UNDERLINE  "\033[4m"
#define STYLE_BLINK      "\033[5m"
#define STYLE_REVERSE    "\033[7m"
#define STYLE_HIDDEN     "\033[8m"
#define STYLE_STRIKE     "\033[9m"

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
