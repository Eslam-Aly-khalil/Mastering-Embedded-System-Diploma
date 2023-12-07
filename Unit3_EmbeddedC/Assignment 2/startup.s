.global reset                         	//making reset section global to all files
reset:                                  
		ldr sp, =stack_top             //to load address of stack pointer (sp)
		bl main                         //branch & link: branch -> to make a branch (intiallizing main). link: to link the address of next instruction
stop: 	b stop                          //branching on stop to make an infinite loop after returning from main
 