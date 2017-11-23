abc.out : queue.o abc.o
	gcc abc.o queue.o -o abc.out

abc.o : abc.c
	gcc -c abc.c -std=c11 -g

queue.o : queue.c
	gcc -c queue.c -std=c11 -g

clean:
	rm *.o *.out
