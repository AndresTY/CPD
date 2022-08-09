GCC = gcc
FLAGS = -ansi -pedantic -Wall

CFLAGS = -lm

PROGS = mmClassic

mmClassic:
	$(GCC) $(FLAGS) modulo.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o $@ $@.o modulo.o $(CFLAGS)

clean:
	$(RM) $(PROGS) *.o
