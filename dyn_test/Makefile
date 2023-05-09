all: main.exe

dynamic.o: dynamic.h dynamic.c
	gcc -c dynamic.c -o dynamic.o

main.exe: main.c dynamic.o
	gcc main.c dynamic.o -o main.exe

clean:
	# del *.o *.exe