all: tests.exe

linkedlist.o: linkedlist.h linkedlist.c
	gcc -c linkedlist.c -o linkedlist.o

tests.exe: tests.c linkedlist.o
	gcc tests.c linkedlist.o -o tests.exe

clean:
	# del *.o *.exe