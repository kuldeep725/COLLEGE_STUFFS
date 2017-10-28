eulerian.out : queue.o graph.o  eulerian.o
	gcc eulerian.o queue.o graph.o -o eulerian.out

eulerian.o : eulerian.c graph.h queue.h
	gcc -c eulerian.c -std=c11 -g

queue.o : queue.c queue.h
	gcc -c queue.c -g

graph.o : graph.c queue.h graph.h
	gcc -c graph.c -g

clean:
	rm *.o *.out
