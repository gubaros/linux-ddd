# Linux Device Dummy Driver

This is a simple Linux kernel driver that logs messages when loaded and unloaded.

## Files

- `dummy_driver.c`: The source code for the dummy driver.
- `Makefile`: The makefile for building the module.

## Prerequisites

Ensure you have the necessary kernel headers installed. On Debian-based systems, you can install them with:

```sh
sudo apt-get install linux-headers-$(uname -r)

