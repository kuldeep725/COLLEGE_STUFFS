stack_as_a_queue.out : stack.o  stack_as_a_queue.o
	gcc stack_as_a_queue.o stack.o -o stack_as_a_queue.out

stack_as_a_queue.o : stack_as_a_queue.c
	gcc -c stack_as_a_queue.c -std=c11 -g

stack.o : stack.c 
	gcc -c stack.c -std=c11 -g

clean:
	rm *.o *.out
