#include "vga.h"

static inline unsigned char make_color(enum vga_color fg, enum vga_color bg)
{
	return fg | bg << 4;
}

static inline unsigned short make_vgaentry(char c, unsigned char color)
{
	unsigned short c16 = c;
	unsigned short color16 = color;
	return c16 | color16 << 8;
}

static inline unsigned int strlen(const char* str)
{
	unsigned int len = 0;
	
	while(str[len] != '\0')
		len++;

	return len;
}

unsigned short s_rand()
{
	bit  = ((lfsr >> 0) ^ (lfsr >> 2) ^ (lfsr >> 3) ^ (lfsr >> 5) ) & 1;
	return lfsr =  (lfsr >> 1) | (bit << 15);
}

unsigned char rand(unsigned char n)
{
	return (unsigned char) (s_rand() % n);
}

unsigned char random_color()
{
	return make_color(rand(16), rand(16));
}

void init_term(void)
{
	term_row = 0;
	term_column = 0;
	term_color = make_color(COLOR_LIGHT_GREEN, COLOR_DARK_GREY);
	term_buffer = (unsigned short*) 0xB8000;

	for(unsigned int y = 0; y < VGA_HEIGHT; y++)
	{
		for(unsigned int x = 0; x < VGA_WIDTH; x++)
		{
			const unsigned int index = y * VGA_WIDTH + x;
			term_buffer[index] = make_vgaentry(' ', term_color);
		}
	}
}

void term_setcolor(unsigned char color)
{
	term_color = color;
}

void term_putentryat(char c, unsigned char color, unsigned int x, unsigned int y)
{
	const unsigned int index = y * VGA_WIDTH + x;
	term_buffer[index] = make_vgaentry(c, color);
  //set_cursor(x + 1, y);
}

void term_putchar(char c)
{
	if(c == '\n')
	{
		term_column = 0;
		term_row++;
    set_cursor(term_column, term_row);
		return;
	}
	if(c == '\t')
	{
		unsigned char less = VGA_WIDTH - term_column;

		if(less >= 4)
		{
			term_column += 4;
		}
		else
		{
			term_column = 4 - less;
			term_row++;
		}
    set_cursor(term_column, term_row);
    
		return;
	}
	else
	{
		term_putentryat(c, term_color, term_column, term_row);
	}

	if(++term_column == VGA_WIDTH)
	{
		term_column = 0;
		if(++term_row == VGA_HEIGHT)
			term_row = 0;
	}
  set_cursor(term_column, term_row);
}

void term_writestring(const char* data)
{
	unsigned int datalen = strlen(data);

	for(unsigned int i = 0; i < datalen; i++)
	{
		term_putchar(data[i]);
	}
}

void write(const char* str)
{
	term_writestring(str);
}

void move_cursor(unsigned short pos)
{
    outb (FB_COMMAND_PORT, FB_HIGH_BYTE_COMMAND);
    outb (FB_DATA_PORT,    ((pos >> 8) & 0x00FF));
    outb (FB_COMMAND_PORT, FB_LOW_BYTE_COMMAND);
    outb (FB_DATA_PORT,    pos & 0x00FF);
}

void set_cursor(unsigned int x, unsigned int y)
{
    move_cursor(y * VGA_WIDTH + x);
    
    fb_cursor_x = x;
    fb_cursor_y = y;
}