main.exe: main.c thread.o
	gcc main.c thread.o -o main.exe

thread.o: thread.h thread.c
	gcc -c thread.c -o thread.o

clean:
	del *.o *.exe