
CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

sim01 : sim01.o config.o metadata.o simulation.o 
	$(CC) $(LFLAGS) sim01.o config.o metadata.o simulation.o -o sim01

sim01.o : sim01.cpp config.h config.cpp metadata.h metadata.cpp simulation.h simulation.cpp
	$(CC) $(CFLAGS) sim01.cpp

metadata.o : metadata.h metadata.cpp
	$(CC) $(CFLAGS) metadata.cpp

config.o : config.h config.cpp
	$(CC) $(CFLAGS) config.cpp

simulation.o : simulation.h simulation.cpp
	$(CC) $(CFLAGS) simulation.cpp

clean:
	rm -rf *.o sim01