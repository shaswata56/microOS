bits 32
section .text
	align	4
	dd	0x1BADB002
	dd	0x00
	dd	- (0x1BADB002 + 0x00)

global start
global kbd_handler
global read_port
global write_port
global load_idt

extern kernel
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

start:
	cli
	mov	esp, stack_space
	call	kernel
	hlt

section .bss
resb 8192
stack_space:
