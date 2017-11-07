cut-vertices.out : stack.o graph.o queue.o cut-vertices.o
	gcc cut-vertices.o stack.o graph.o queue.o -o cut-vertices.out

cut-vertices.o : cut-vertices.c
	gcc -c cut-vertices.c -std=c11 -g

stack.o : stack.c
	gcc -c stack.c -g

queue.o : queue.c
	gcc -c queue.c -g

graph.o : graph.c
	gcc -c graph.c -g

clean:
	rm *.o *.out
