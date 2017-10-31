dfs.out : queue.o graph.o  dfs.o
	gcc dfs.o queue.o graph.o -o dfs.out

dfs.o : dfs.c graph.h queue.h
	gcc -c dfs.c -std=c11 -g

queue.o : queue.c queue.h
	gcc -c queue.c -g

graph.o : graph.c queue.h graph.h
	gcc -c graph.c -g

clean:
	rm *.o *.out
