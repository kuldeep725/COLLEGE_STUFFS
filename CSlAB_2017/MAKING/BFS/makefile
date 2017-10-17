CC = gcc
OBJS = main.o graphlib.o queue.o

a.out : ${OBJS}
	${CC} ${OBJS}

main.o: main.c
	${CC} -c main.c

graphlib.o : graphlib.c
	${CC} -c graphlib.c

queue.o : queue.c
	${CC} -c queue.c

clean:
	\rm a.out *.o *.dot
