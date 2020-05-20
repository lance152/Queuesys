cc = g++
CFLAGS = -std=c++11

all: main.o Queue.o QueueSystem.o
	$(CC) $(CFLAGS) main.o Queue.0 QueueSystem.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Queue.o: Queue.cpp
	$(CC) $(CFLAGS) -c Queue.cpp

QueueSystem.o:QueueSystem.cpp
	$(CC) $(CFLAGS) -c QueueSystem.cpp
