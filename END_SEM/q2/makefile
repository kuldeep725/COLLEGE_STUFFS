distance-2Coloring.out : stack.o graph.o queue.o distance-2Coloring.o
	gcc distance-2Coloring.o stack.o graph.o queue.o -o distance-2Coloring.out

distance-2Coloring.o : distance-2Coloring.c
	gcc -c distance-2Coloring.c -std=c11 -g

stack.o : stack.c
	gcc -c stack.c -std=c11 -g

queue.o : queue.c
	gcc -c queue.c -std=c11 -g

graph.o : graph.c
	gcc -c graph.c -std=c11 -g

clean:
	rm *.o *.out
