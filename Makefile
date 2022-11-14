# Makefile for Writing Make Files Example
 
# *****************************************************
# Variables to control Makefile operation

INCLUDE_DIR := inc
SRC_DIR := src

CC := g++
CFLAGS := -Wall -g -std=c++2a
OUTPUT := main
 
all: clean main.o Card.o
	$(CC) $(CFLAGS) -o $(OUTPUT) main.o Card.o
	
main.o: $(SRC_DIR)/main.cpp $(INCLUDE_DIR)/Card.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/main.cpp

Card.o: $(SRC_DIR)/Card.cpp $(INCLUDE_DIR)/Card.hpp $(INCLUDE_DIR)/Common.hpp $(INCLUDE_DIR)/CardException.hpp
	$(CC) $(CFLAGS) -c $(SRC_DIR)/Card.cpp

Player.o: $(SRC_DIR)/Card.cpp $(INCLUDE_DIR)/Card.hpp

clean:
	rm -rf  *.o $(OUTPUT)