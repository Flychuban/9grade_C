all: smarthause.exe main.exe

smarthause.exe: 
	gcc smarthause.c -o smarthause.exe

main.exe: main.c product.o
	gcc main.c product.o -o main.exe

product.o: product.c product.h
	gcc -c product.c -o product.o

clean:
	rm -f *o *exe