#ifndef INCLUDE_VGA_H
#define INCLUDE_VGA_H

enum vga_color {
	COLOR_BLACK = 0,
	COLOR_BLUE  = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN  = 3,
	COLOR_RED   = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN   = 6,
	COLOR_LIGHT_GREY  = 7,
	COLOR_DARK_GREY   = 8,
	COLOR_LIGHT_BLUE  = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN  = 11,
	COLOR_LIGHT_RED   = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN   = 14,
	COLOR_WHITE	    = 15,
};

static unsigned short lfsr = 0xACE1u;
unsigned short bit;

static const unsigned int VGA_WIDTH = 80;
static const unsigned int VGA_HEIGHT = 25;

unsigned int term_row;
unsigned int term_column;
unsigned char term_color;
unsigned short* term_buffer;

static inline unsigned char make_color(enum vga_color fg, enum vga_color bg);

static inline unsigned short make_vgaentry(char c, unsigned char color);

static inline unsigned int strlen(const char* str);

unsigned short s_rand();

unsigned char rand(unsigned char n);

unsigned char random_color();

void init_term(void);

void term_setcolor(unsigned char color);

void term_putentryat(char c, unsigned char color, unsigned int x, unsigned int y);

void term_putchar(char c);

void term_writestring(const char* data);

void write(const char* str);

#endif