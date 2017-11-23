abc.out : stack.o abc.o
	gcc abc.o stack.o -o abc.out

abc.o : abc.c
	gcc -c abc.c -std=c11 -g

stack.o : stack.c
	gcc -c stack.c -std=c11 -g

clean:
	rm *.o *.out
