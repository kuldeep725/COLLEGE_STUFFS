shortRed.out : queue.o graph.o shortRed.o
	gcc queue.o graph.o shortRed.o -o shortRed.out

shortRed.o : shortRed.c graph.h queue.h
	gcc -c shortRed.c graph.c -std=c11 -g

queue.o : queue.c queue.h
	gcc -c queue.c -g

graph.o : graph.h  queue.h graph.c
	gcc -c graph.c -g

clean:
	rm *.o *.out
