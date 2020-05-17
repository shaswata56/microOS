## microOS

![Screenplay](https://raw.githubusercontent.com/shaswata56/microOS/master/res/screenplay.gif)

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

