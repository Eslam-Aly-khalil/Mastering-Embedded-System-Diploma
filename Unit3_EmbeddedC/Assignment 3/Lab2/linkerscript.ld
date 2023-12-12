/*
LinkerScript for cortex-m3
Eslam Aly
*/

MEMORY
{
	flash(RX) : ORIGIN = 0X08000000 ,LENGTH = 128K
	sram(RWX) : ORIGIN = 0X20000000 ,LENGTH = 20K 
}

SECTIONS
{
	.text : {
			*(.vectors*)              /*taking all .vectors sections (all sections begin with vectors) from all .o files*/
			*(.text*)
			*(.rodata*)
	
	}> flash
	
	.data : {
			*(.data*)
	}> flash
	
	.bss : {
			*(.bss*)
	}> sram
}
