hamiltonian.out : queue.o stack.o graph.o  hamiltonian.o
	gcc hamiltonian.o queue.o stack.o graph.o -o hamiltonian.out

hamiltonian.o : hamiltonian.c
	gcc -c hamiltonian.c -std=c11 -g

queue.o : queue.c
	gcc -c queue.c -std=c11 -g

graph.o : graph.c
	gcc -c graph.c -std=c11 -g

stack.o : stack.c
	gcc -c stack.c -std=c11 -g
clean:
	rm *.o *.out
