CC = gcc
CFLAGS = -std=c18
CFLAGS_W = -Wall -Wextra -pedantic -std=c99
LDFLAGS = -lm -lpthread
SRC = main.c
TARGET = main

all:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

safe:
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(TARGET)

.PHONY: all clean