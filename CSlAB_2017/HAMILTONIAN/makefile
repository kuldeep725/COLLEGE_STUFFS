hamiltonian.out : hamiltonian.o queue.o graph.o
	gcc hamiltonian.o queue.o graph.o -o hamiltonian.out
hamiltonian.o : hamiltonian.c graph.c queue.c
	gcc -c hamiltonian.c graph.c queue.c -std=c11

queue.o : queue.c graph.c
	gcc -c queue.c

graph.o : graph.c
	gcc -c graph.c
clean:
	rm *.o *.out
