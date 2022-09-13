#*************************************************
#Fecha: 09-agosto-2022
#Autor: Juan Pablo Barrios Suarez
#Materia: Parallel and Distribuited Computing
#Tema: Construcción Benchmark Multiplicación de matrices
#Tòpico: Script Automatizacion Compilacion
#*************************************************/

GCC = gcc
FLAGS = -ansi -std=c11 -pedantic -Wall -D_POSIX_C_SOURCE=199309L
MATHFLAG = -lm -lpthread -fopenmp

PROGRS = mm_main_double mm_main_double_rnd

all: $(PROGRS) 

mm_main_double: 
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)

mm_main_double_rnd: 
	$(GCC) $(FLAGS) -c $@.c
	$(GCC) $(FLAGS) -c mm_lib.c
	$(GCC) $(FLAGS) -o $@ $@.o mm_lib.o $(MATHFLAG)
	
clean: 
	$(RM) *.o $(PROGRS)
	