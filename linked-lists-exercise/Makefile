all: app.exe

hierarchy.o: hierarchy.h hierarchy.c
	gcc -c hierarchy.c -o hierarchy.o

app.exe: app.c hierarchy.o
	gcc app.c hierarchy.o -o app.exe

clean:
	del *.o *.exe