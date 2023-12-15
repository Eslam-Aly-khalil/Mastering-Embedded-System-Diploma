/*
LinkerScript for cortex-m3 & startup.c
Eslam Aly
*/

MEMORY
{
	flash(RX) : ORIGIN = 0X00000000 ,LENGTH = 512M
	sram(RWX) : ORIGIN = 0X20000000 ,LENGTH = 512M
}

SECTIONS
{
	.text : {
			*(.vectors*)              /*taking all .vectors sections (all sections begin with vectors) from all .o files*/
			*(.text*)
			*(.rodata*)
			_E_text = .;	
	}> flash
	
	.data : {
			_S_data = .;
			*(.data*)
			. = ALIGN(4);
			_E_data = .;
	}> sram AT> flash
	
	.bss : {
			_S_bss = .;
			*(.bss*)
			_E_bss = .;
	}> sram
}
