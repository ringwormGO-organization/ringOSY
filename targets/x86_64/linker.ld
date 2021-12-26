ENTRY(start)

SECTIONS
{
    . = 1M;

    .boot : 
    {
        KEEP(*(.multiboot_header))
    }

    .text : ALIGN(0x1000)
    {
        *(.text)
    }
    .data : ALIGN(0x1000)
	{
		*(.data)
	}
	.rodata : ALIGN(0x1000)
	{
		*(.rodata)
	}
	.bss : ALIGN(0x1000)
	{
		*(COMMON)
		*(.bss)
	}
}