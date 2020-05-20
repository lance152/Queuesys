cc = g++
CFLAGS = -std=c++11

all: Queue.o QueueSystem.o main.o
	$(CC) $(CFLAGS) main.o Queue.o QueueSystem.o -o main

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

Queue.o: Queue.cpp
	$(CC) $(CFLAGS) -c Queue.cpp

QueueSystem.o:QueueSystem.cpp
	$(CC) $(CFLAGS) -c QueueSystem.cpp
