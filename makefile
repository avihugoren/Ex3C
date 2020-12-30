CFLAGS= -Wall -g

all:isort txtfind

isort:isort.o
	gcc $(CFLAGS) isort.o  -o isort

txtfind:txtfind.o
	gcc $(CFLAGS) txtfind.o  -o txtfind	

isort.o:isort.c
	gcc $(CFLAGS) -c isort.c

txtfind.o:
	gcc $(CFLAGS) -c txtfind.c

.PHONY: clean all

clean:
	rm -f *.o isort txtfind
