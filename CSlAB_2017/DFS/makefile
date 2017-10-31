dfs.out : stack.o graph.o queue.o dfs.o
	gcc dfs.o stack.o graph.o queue.o -o dfs.out

dfs.o : dfs.c graph.h stack.h
	gcc -c dfs.c -std=c11 -g

stack.o : stack.c stack.h
	gcc -c stack.c -g

queue.o : queue.c queue.h
	gcc -c queue.c -g

graph.o : graph.c queue.h graph.h
	gcc -c graph.c -g

clean:
	rm *.o *.out
