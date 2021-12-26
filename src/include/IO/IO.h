#pragma once

#include <stdint.h>
#include <stddef.h>

void outb(unsigned short port, unsigned char val);
void outw(unsigned short int port, unsigned short int data);
unsigned char inb(unsigned short port);
void io_wait();
void RemapPIC();