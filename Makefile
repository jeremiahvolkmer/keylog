CC = gcc 

all: main.o keylog.o
	$(CC) keylog.o main.o -o tst

main.o: main.c keylog.o
	$(CC) -c main.c

keylog.o: keylog.c keylog.h
	$(CC) -c  keylog.c

clean:
	rm -rf *.o
	rm -rf tst
	rm -rf Binary

