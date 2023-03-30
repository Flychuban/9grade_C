all: safeadd.exe safesubtract.exe safemultiply.exe safedivide.exe

safeadd.exe: safeadd.c safeint.o
	gcc safeadd.c safeint.o -o safeadd.exe

safesubtract.exe: safesubtract.c safeint.o
	gcc safesubtract.c safeint.o -o safesubtract.exe

safemultiply.exe: safemultiply.c safeint.o
	gcc safemultiply.c safeint.o -o safemultiply.exe

safedivide.exe: safedivide.c safeint.o
	gcc safedivide.c safeint.o -o safedivide.exe

safeint.o: safeint.h safeint.c
	gcc -c safeint.c -o safeint.o

clean:
	del *.o *.exe
