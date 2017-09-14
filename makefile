CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

sim01 : sim01.o config.o
	$(CC) $(LFLAGS) sim01.o config.o -o sim01

clean:
	rm -rf *.o Sim01