main.exe: quadraticroots.o main.c
	gcc main.c quadraticroots.o -lm -o main.exe
quadraticroots.o: quadraticroots.c quadraticroots.h
	gcc -c quadraticroots.c -o quadraticroots.o
clean:
	del *.o *.exe