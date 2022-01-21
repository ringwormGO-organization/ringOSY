// Includes
#include "main.h"


// Kernel main
extern "C" void kernel_main() 
{
    PrintStuff();
}

void PrintStuff()
{
    print_clear();
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    printf("Welcome to ringOSY!!\n");
    print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLACK);
    printf(to_string(320));
    SetCursorPosition(1000);
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_WHITE);
    print_str2("Test");
}