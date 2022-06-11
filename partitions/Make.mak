#CC = gcc
#CC = g++
#FLAGS = -Wall -g
#includedir = ./../Utils
#INCLUDEDIR = -I. -I$(includedir)
#LIB = -lm

.PHONY: clean distclean

target: 
	gcc -c main.c
	gcc -c partition.c
	gcc -c ../Utils/PrintArray.c
	

clean:
	rm -rf *~
	rm -rf *bak*
	rm -rf core

distclean: clean
	rm -rf myExe
	rm -rf *.o