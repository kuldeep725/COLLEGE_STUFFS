hamiltonian.out : queue.o graph.o  hamiltonian.o
	gcc hamiltonian.o queue.o graph.o -o hamiltonian.out

hamiltonian.o : hamiltonian.c graph.h queue.h
	gcc -c hamiltonian.c -std=c11 -g

queue.o : queue.c queue.h
	gcc -c queue.c -g

graph.o : graph.c queue.h graph.h
	gcc -c graph.c -g

clean:
	rm *.o *.out
