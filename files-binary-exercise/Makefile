all: app.exe

linkedlists.o: linkedlists.h linkedlists.c
	gcc -c linkedlists.c -o linkedlists.o

app.exe: app.c linkedlists.o
	gcc app.c linkedlists.o -o app.exe

clean:
	# del *.o *.exe