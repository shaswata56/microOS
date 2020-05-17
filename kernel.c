#include "kbd_map.h"

void kernel(void)
{

	init_term();
	write("\t\t\t\tWelcome to microOS!!!\nroot@kernel# ");

	idt_init();
	kbd_init();

	while(1);
}
