#@copyright : Eslam
CC=	arm-none-eabi-
CFLAGS= -mthumb	-mcpu=cortex-m3 -g
INCS=	-I .
LIB=
SRC=	$(wildcard *.c)
OBJ=	$(SRC:.c=.o)
AS=	$(wildcard *.s)
ASOBJ=	$(AS:.s=.o) 
Project_name= learn-in-depth_arm_cortex_m3

all:	$(Project_name).bin
	@echo "------Build is DONE-----"
	
startup.o:	startup.s
	$(CC)as.exe $(CFLAGS) $< -o $@

%.o:	%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@

$(Project_name).elf:	$(OBJ) $(ASOBJ)
	$(CC)ld.exe	 -T linkerscript.ld $(LIBS) $(ASOBJ) $(OBJ) -o $@  -Map=Map_file.map

$(Project_name).bin:	$(Project_name).elf 
	$(CC)objcopy.exe -O binary $< $@ 

clean_all:
	rm	*.o *.elf *.bin
	@echo "-----All Compiled Files are Deleted-----"
	
clean:
	rm	*.elf *.bin
	@echo "-----.elf & .bin Files are Deleted-----"