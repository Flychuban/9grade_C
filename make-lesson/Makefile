main.exe : main.c maths.o
	gcc main.c maths.o -o main.exe

maths.o: maths.c maths.h
	gcc -c maths.c -o maths.o
clean:
	del *.0 *.exe