#pragma once

#include <stdint.h>
#include <stddef.h>

void outb(unsigned short port, unsigned char val);
unsigned char inb(unsigned short port);
void RemapPIC();