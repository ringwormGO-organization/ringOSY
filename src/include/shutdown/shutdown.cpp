#include "shutdown.h"


void shutdown(int type)
{
    switch (type)
    {
        case 0:
            outw(0x604, 0x2000);
            break;
        case 1:
            outw(0xB004, 0x2000);
            break;
        case 2:
            outw(0x4004, 0x3400);
            break;
    
        default:
            print_str("Unable to shutdown machine...");
            break;
    }
}