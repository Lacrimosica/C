#CC = gcc
#CC = g++
#FLAGS = -Wall -g
includedir = ../Utils/
INCLUDEDIR = -I. -I$(includedir)
#LIB = -lm

.PHONY: clean distclean

target: 
	gcc -c main.c
	gcc -c partition.c
	gcc -c $(INCLUDEDIR) printArray.c
	gcc -Wall $(INCLUDEDIR) -g -o exe main.o partition.o printArray.o

clean:
	rm -rf *~
	rm -rf *bak*
	rm -rf core

distclean: clean
	rm -rf myExe
	rm -rf *.o