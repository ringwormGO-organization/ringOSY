//for accessing kernel
#pragma once

#include "../include/BasicRenderer/print.hpp"
#include "../libc/stdio.hpp"

struct multiboot_tag_framebuffer
{
    
};


extern "C" void kernel_main(multiboot_tag_framebuffer* bootInfo);