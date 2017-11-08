abc.out : stack.o graph.o queue.o abc.o
	gcc abc.o stack.o graph.o queue.o -o abc.out

abc.o : abc.c
	gcc -c abc.c -std=c11 -g

stack.o : stack.c
	gcc -c stack.c -std=c11 -g

queue.o : queue.c
	gcc -c queue.c -std=c11 -g

graph.o : graph.c
	gcc -c graph.c -std=c11 -g

clean:
	rm *.o *.out
