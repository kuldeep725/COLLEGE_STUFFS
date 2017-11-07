hamiltonian.out : queue.o stack.o graph.o  hamiltonian.o 
	gcc hamiltonian.o queue.o stack.o graph.o -o hamiltonian.out

hamiltonian.o : hamiltonian.c
	gcc -c hamiltonian.c -std=c11 -g

queue.o : queue.c
	gcc -c queue.c -g

graph.o : graph.c 
	gcc -c graph.c -g

stack.o : stack.c
	gcc -c stack.c -g
clean:
	rm *.o *.out
