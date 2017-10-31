dijkstra.out : queue.o graph.o  dijkstra.o
	gcc dijkstra.o queue.o graph.o -o dijkstra.out

dijkstra.o : dijkstra.c graph.h queue.h
	gcc -c dijkstra.c -std=c11 -g

queue.o : queue.c queue.h
	gcc -c queue.c -g

graph.o : graph.c queue.h graph.h
	gcc -c graph.c -g

clean:
	rm *.o *.out
