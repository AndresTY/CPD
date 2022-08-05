GCC = gcc


FLAGS = -ansi -pedantic -Wall -lm 
FLAGSC = -Wall -lm 

MODULO = taller1

EJECT = ./app

app:
	$(GCC) $(FLAGSC) -c $(MODULO).c
	$(GCC) $(FLAGSC) -c $@.c
	$(GCC) $(FLAGS) -o $@ $@.o $(MODULO).o

clear:
	$(RM) app *.o

clean:
	$(RM) *.o

product:
	$(EJECT) 1

test:
	$(EJECT) 0

day_to_date:
	$(EJECT) 2

distancia:
	$(EJECT) 3

sequence:
	$(EJECT) 4


triangle:
	$(EJECT) 5

Identity:
	$(EJECT) 6

rand:
	$(EJECT) 7

sum_NxN:
	$(EJECT) 8

sub_NxN:
	$(EJECT) 9

mult_NxN:
	$(EJECT) 10

