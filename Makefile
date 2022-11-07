# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation

INCLUDE_DIR := inc
SRC_DIR := src

CC := g++
CFLAGS := -Wall -g -std=c++2a
OUTPUT := main
 
all: main.o Card.o
	$(CC) $(CFLAGS) -o $(OUTPUT) main.o Card.o
	
main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/Card.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp

Card.o: $(SRC_DIR)/Card.cpp $(INCLUDE_DIR)/Card.h
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Card.cpp

clean:
	rm -rf  *.o