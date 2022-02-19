// Includes
#include "main.hpp"

// Kernel main
extern "C" void kernel_main(multiboot_tag_framebuffer* BootInfo) 
{
    clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    print_str("Welcome to ringOSY!!\n");
    print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_WHITE);
    print_str(to_string(320));
}