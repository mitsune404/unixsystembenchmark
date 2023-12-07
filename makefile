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
		./main

test:
	rm -f ./sandbox/test
	$(CC) ./sandbox/test.c -o ./sandbox/test -lpthread

test2:
	rm -f ./sandbox/test2
	$(CC) ./sandbox/test2.c -o ./sandbox/test2

clean:
	rm -f $(TARGET)

CLEAN:
	rm -f ./sandbox/test
	rm -f ./sandbox/test2
	rm -f $(TARGET)

.PHONY: all clean test