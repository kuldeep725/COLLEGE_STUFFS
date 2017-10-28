color_6.out : queue.o graph.o  color_6.o
	gcc color_6.o queue.o graph.o -o color_6.out

color_6.o : color_6.c graph.h queue.h
	gcc -c color_6.c -std=c11 -g

queue.o : queue.c queue.h
	gcc -c queue.c -g

graph.o : graph.c queue.h graph.h
	gcc -c graph.c -g

clean:
	rm *.o *.out
