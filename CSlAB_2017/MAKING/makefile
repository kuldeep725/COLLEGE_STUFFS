foo.out : foo.o making.o
	gcc foo.o making.o -o foo.out
foo.o : foo.c making.c
	gcc -c foo.c making.c -std=c11

making.o : making.c making.h
	gcc -c making.c

clean:
	rm foo.o
