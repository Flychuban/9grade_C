all: main.exe

main.exe: lists.o main.c
	gcc tests.c linkedlist.o -o tests.exe

lists.o: lists.h lists.c
	gcc -c lists.c -o lists.o

clean:
	del *.o *.exe