
all: mainProg 

mainProg: main.o  myBank.o
	gcc -Wall -g -o mainProg main.o myBank.o 

main.o: main.c bankFunction.h
	gcc -Wall -g -c main.c 

myBank.o: myBank.c bankFunction.h
	gcc -Wall -g -c myBank.c 

.PHONY: clean all 

clean: 
	rm *.o -f mainProg
