all: idapp.exe

idapp.exe: dynarr.o idapp.c
	gcc idapp.c dynarr.o -o idapp.exe

dynarr.o: dynarr.h dynarr.c
	gcc -c dynarr.c -o dynarr.o

clean:
	del *.exe *.o