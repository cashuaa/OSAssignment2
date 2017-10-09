
CC = g++
DEBUG = -g
CFLAGS = -Wall -c
LFLAGS = -Wall

sim02 : sim02.o config.o metadata.o simulation.o SimpleTimer.o MemoryFunction.o
	$(CC) $(LFLAGS) sim02.o config.o metadata.o simulation.o SimpleTimer.o MemoryFunction.o -o sim02

sim02.o : sim02.cpp config.h config.cpp metadata.h metadata.cpp simulation.h simulation.cpp SimpleTimer.h SimpleTimer.cpp MemoryFunction.h MemoryFunction.c
	$(CC) $(CFLAGS) sim02.cpp

metadata.o : metadata.h metadata.cpp
	$(CC) $(CFLAGS) metadata.cpp

MemoryFunction.o : MemoryFunction.h MemoryFunction.c
	$(CC) $(CFLAGS) MemoryFunction.c

config.o : config.h config.cpp
	$(CC) $(CFLAGS) config.cpp

SimpleTimer.o : SimpleTimer.h SimpleTimer.cpp
	$(CC) $(CFLAGS) SimpleTimer.cpp

simulation.o : simulation.h simulation.cpp
	$(CC) $(CFLAGS) simulation.cpp

clean:
	rm -rf *.o sim02