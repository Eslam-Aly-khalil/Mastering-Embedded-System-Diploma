#@copyright : Eslam
CC=	arm-none-eabi-
CFLAGS= -mthumb	-mcpu=cortex-m4 -gdwarf-2 -g
INCS=	-I .
LIB=
SRC=	$(wildcard *.c)
OBJ=	$(SRC:.c=.o)
AS=	$(wildcard *.s)
ASOBJ=	$(AS:.s=.o) 
Project_name= unit3_Assignment4_cortex-m4

all:	$(Project_name).bin
	@echo "------Build is DONE-----"

%.o:	%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_name).elf:	$(OBJ) $(ASOBJ)
	$(CC)ld.exe	 -T linkerscript.ld $(LIBS) $(ASOBJ) $(OBJ) -o $@  -Map=Map_file.map
	cp	$(Project_name).elf		$(Project_name).axf 

$(Project_name).bin:	$(Project_name).elf 
	$(CC)objcopy.exe -O binary $< $@ 

clean_all:
	rm	*.o *.elf *.bin
	@echo "-----All Compiled Files are Deleted-----"
	
clean:
	rm	*.elf *.bin
	@echo "-----.elf & .bin Files are Deleted-----"