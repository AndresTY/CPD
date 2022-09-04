GCC = gcc
FLAGS = -ansi -pedantic -Wall

CFLAGS = -lm

PROGS = mmClassic mmClassicRND

all: $(PROGS)

mmClassicRND:
	$(GCC) $(FLAGS) modulo.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o $@ $@.o modulo.o $(CFLAGS)

mmClassic:
	$(GCC) $(FLAGS) modulo.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o $@ $@.o modulo.o $(CFLAGS)

mmClassic_int:
	$(GCC) $(FLAGS) modulo.c -c
	$(GCC) $(FLAGS) $@.c -c
	$(GCC) $(FLAGS) -o $@ $@.o modulo.o $(CFLAGS)
clean:
	$(RM) $(PROGS) *.o
