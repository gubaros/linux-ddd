# Linux Device Dummy Driver

[![Codacy Badge](https://api.codacy.com/project/badge/Grade/786652307adb4d48a9443e55d3adc6db)](https://app.codacy.com/gh/gubaros/linux-ddd?utm_source=github.com&utm_medium=referral&utm_content=gubaros/linux-ddd&utm_campaign=Badge_Grade)

This is a simple Linux kernel driver that logs messages when loaded and unloaded.

## Files

- `dummy_driver.c`: The source code for the dummy driver.
- `Makefile`: The makefile for building the module.

## Prerequisites

Ensure you have the necessary kernel headers installed. On Debian-based systems, you can install them with:

```sh
sudo apt-get install linux-headers-$(uname -r)
```
## Context, linux/init.h

In the Linux kernel, the init.h header file provides macros for specifying the initialization and cleanup functions for kernel modules.
__init Macro

The __init macro is used to mark a function as an initialization function. When the kernel is built with certain options, the memory used by these functions can be freed after the initialization is complete, which helps save memory.
module_init Macro

The module_init macro is used to declare the function that will be called when the module is loaded. It takes the name of the initialization function as an argument.
