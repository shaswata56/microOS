all:	boot kernel
	ld -m elf_i386 -T linker.ld -o microOS.bin boot.o kernel.o
	strip microOS.bin
	rm kernel.o boot.o

boot:	boot.asm
	nasm -f elf32 boot.asm -o boot.o

kernel:	kernel.c
	gcc -fno-stack-protector -m32 -c kernel.c -o kernel.o

iso:	all
	./check_n_pack.sh
	rm microOS.bin

clean:	
	rm microOS.bin *.o
