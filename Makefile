CC=gcc
CFLAGS=-Wall -Wextra

all: organizer

organizer: src/main.c
	$(CC) $(CFLAGS) -o organizer src/main.c

clean:
	rm -f organizer
