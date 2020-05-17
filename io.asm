bits 32

global kbd_handler
global read_port
global write_port
global load_idt

extern kbd_main

read_port:
	mov	edx, [esp + 4]
	in	al, dx
	ret

write_port:
	mov	edx, [esp + 4]    
	mov	al, [esp + 4 + 4]  
	out	dx, al  
	ret

load_idt:
	mov	edx, [esp + 4]
	lidt	[edx]
	sti
	ret

kbd_handler:                 
	call	kbd_main
	iretd