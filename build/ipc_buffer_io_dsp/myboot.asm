    .global _my_boot
    .sect "my_boot_sect"
	.align 128
	.global _c_int00 
_my_boot:
	B    _c_int00
	NOP 5
