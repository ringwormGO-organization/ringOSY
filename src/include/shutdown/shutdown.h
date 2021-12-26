#pragma once

#include "../IO/IO.h"
#include "../BasicRenderer/print.h"

/* Types:
    0: Newer versions of Qemu
    1: Bochs, and older versions of Qemu(than 2.0)
    2: Virtual Box
*/

void shutdown(int type);