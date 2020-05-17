all:	boot kernel
	ld -m elf_i386 -T linker.ld -o microOS.bin boot.o io.o kernel.o kbd.o vga.o
	strip microOS.bin
	rm *.o

boot:	boot.asm
	nasm -f elf32 boot.asm -o boot.o

kernel:	io.asm kernel.c kbd.c vga.c
	nasm -f elf32 io.asm -o io.o
	gcc -fno-stack-protector -m32 -c kernel.c -o kernel.o
	gcc -fno-stack-protector -m32 -c kbd.c -o kbd.o
	gcc -fno-stack-protector -m32 -c vga.c -o vga.o

iso:	all
	./check_n_pack.sh
	rm microOS.bin

clean:	
	rm microOS.bin *.o
