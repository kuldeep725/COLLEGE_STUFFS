path_finder.out : queue.o graph.o  path_finder.o
	gcc path_finder.o queue.o graph.o -o path_finder.out

path_finder.o : path_finder.c graph.h queue.h
	gcc -c path_finder.c -std=c11 -g

queue.o : queue.c queue.h
	gcc -c queue.c -g

graph.o : graph.c queue.h graph.h
	gcc -c graph.c -g

clean:
	rm *.o *.out
