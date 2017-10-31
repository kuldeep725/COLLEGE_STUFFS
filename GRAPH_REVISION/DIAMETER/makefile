diameter.out : queue.o graph.o  diameter.o
	gcc diameter.o queue.o graph.o -o diameter.out

diameter.o : diameter.c graph.h queue.h
	gcc -c diameter.c -std=c11 -g

queue.o : queue.c queue.h
	gcc -c queue.c -g

graph.o : graph.c queue.h graph.h
	gcc -c graph.c -g

clean:
	rm *.o *.out
