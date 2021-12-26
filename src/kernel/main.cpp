// Includes
#include "main.h"

// Kernel main
extern "C" void kernel_main() 
{
    // Clear the screen
    print_clear();
    // Set the front and back colors
    print_set_color(PRINT_COLOR_YELLOW, PRINT_COLOR_BLACK);
    // Print "Welcome to ringOSY!!"
    print_str("Welcome to ringOSY!!\n");
    //Change color
    print_set_color(PRINT_COLOR_CYAN, PRINT_COLOR_BLACK);
    //New line
    print_str("New line\n");
    //Print integer
    print_str(to_string(320));
    //Set Cursor Position to 1000
    SetCursorPosition(1000);
    // Colors change
    print_set_color(PRINT_COLOR_RED, PRINT_COLOR_WHITE);
    //Printing text at 1000 cursor position
    print_str2("Test");
}