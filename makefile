all: ArvoreBin.o
	gcc main.c ArvoreBin.c -o prog
	./prog


ArvoreBin.o: ArvoreBin.c
	gcc -c ArvoreBin.c

clean:
	rm *.o prog