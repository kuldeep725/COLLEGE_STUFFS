<<<<<<< HEAD
hamiltonian.out : queue.o stack.o graph.o  hamiltonian.o 
	gcc hamiltonian.o queue.o stack.o graph.o -o hamiltonian.out

hamiltonian.o : hamiltonian.c
	gcc -c hamiltonian.c -std=c11 -g

queue.o : queue.c
	gcc -c queue.c -g

graph.o : graph.c 
=======
abc.out : stack.o graph.o queue.o abc.o
	gcc abc.o stack.o graph.o queue.o -o abc.out

abc.o : abc.c
	gcc -c abc.c -std=c11 -g

stack.o : stack.c
	gcc -c stack.c -g

queue.o : queue.c
	gcc -c queue.c -g

graph.o : graph.c
>>>>>>> 21345d35cd5e4822c99d9e4c3e9a5dc3339a451d
	gcc -c graph.c -g

stack.o : stack.c
	gcc -c stack.c -g
clean:
	rm *.o *.out
