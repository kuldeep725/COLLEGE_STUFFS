counting_pieces.out : queue.o graph.o  counting_pieces.o
	gcc counting_pieces.o queue.o graph.o -o counting_pieces.out

counting_pieces.o : counting_pieces.c graph.h queue.h
	gcc -c counting_pieces.c -std=c11 -g

queue.o : queue.c queue.h
	gcc -c queue.c -g

graph.o : graph.c queue.h graph.h
	gcc -c graph.c -g

clean:
	rm *.o *.out
