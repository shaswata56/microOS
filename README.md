## microOS

![Screenshot](https://raw.githubusercontent.com/shaswata56/OS/master/Operating_System_CourseWork/res/screen.png)

I've written this minimal OS by following the OSDev tutorial. Currently it supports only kernel mode, no usermode implemented and no plan to do it.
It can be easily run under qemu / burn on a usb and test it on bare metal.
For Qemu:

```sh
    qemu-system-i386 -cdrom microOS.iso
```

or,

```sh
    qemu-system-i386 -kernel microOS.bin
```

