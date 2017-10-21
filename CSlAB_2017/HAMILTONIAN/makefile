hamiltonian.out : queue.o graph.o  hamiltonian.o
	gcc hamiltonian.o queue.o graph.o -o hamiltonian.out

queue.o : queue.c graph.c
	gcc -c queue.c -g

graph.o : graph.c
	gcc -c graph.c -g

hamiltonian.o : hamiltonian.c graph.c queue.c
	gcc -c hamiltonian.c graph.c queue.c -std=c11 -g

clean:
	rm *.o *.out
