distance.out : stack.o graph.o queue.o distance.o
	gcc distance.o stack.o graph.o queue.o -o distance.out

distance.o : distance.c
	gcc -c distance.c -std=c11 -g

stack.o : stack.c
	gcc -c stack.c -std=c11 -g

queue.o : queue.c
	gcc -c queue.c -std=c11 -g

graph.o : graph.c
	gcc -c graph.c -std=c11 -g

clean:
	rm *.o *.out
