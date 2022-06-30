
application_header_only: 
	gcc-10 main.c -o main.elf -lm

application_static: staticlib
	gcc-10 main_Erw_Sta.c -lstaticlib -o main_Erw_Sta.elf -lm

staticlib:
	gcc-10 staticlib.c -c
	ar -crs libstaticlib.a staticlib.o
	sudo cp staticlib.h /usr/include
	sudo cp libstaticlib.a /usr/lib

