cc=gcc
AR=ar
FLAGS= -Wall 

all: targil1 targil2

targil1: isort.o 
		$(CC) $(FLAGS) -o targil1 isort.o 
targil2: txtfind.o 
		$(CC) $(FLAGS) -o targil2 txtfind.o

isort.o: isort.c  
	$(CC) $(FLAGS) -c isort.c 

txtfind.o: txtfind.c
	$(CC) $(FLAGS) -c txtfind.c 

clean:
	rm -f *.o *.a *.so *.out progmains progmaind

.PHONY: clean all