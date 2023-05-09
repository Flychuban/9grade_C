all: main.exe

d-linked-list.o: d-linked-list.h d-linked-list.c
	gcc -c d-linked-list.c -o d-linked-list.o

main.exe: main.c d-linked-list.o
	gcc main.c d-linked-list.o -o main.exe

clean:
	# del *.o *.exe