GCC = gcc
FLAGS = -ansi -pedantic -Wall

CFlAGS = -lpthread -fopenmp

PROGS = pthreadMM

pthreadMM:
	$(GCC) $(FLAGS) -o $@ $@.c $(CFlAGS)

clean:
	$(RM) $(PROGS) *.o
