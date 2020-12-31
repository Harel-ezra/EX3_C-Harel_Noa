cc=gcc
AR=ar
FLAGS= -Wall 

all: firstTargil.o secondTargil.o

firstTargil.o: isort.c  
	$(CC) $(FLAGS) -c isort.c 

secondTargil.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c 

clean:
	rm -f *.o *.a *.so *.out progmains progmaind

.PHONY: clean all