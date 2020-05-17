#!/bin/sh

if grub-file --is-x86-multiboot microOS.bin; then
	echo Multiboot Confirmed!!!
	mkdir -p isodir/boot/grub
	cp grub.cfg isodir/boot/grub/grub.cfg
	cp microOS.bin isodir/boot/microOS.bin
	grub-mkrescue -o microOS.iso isodir
else
	echo [ERROR] The file is not multiboot.
fi
