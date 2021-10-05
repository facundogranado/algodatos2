
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99
CC=gcc
sorter:
		$(CC) $(CFLAGS) -c helpers.c sort.c
		$(CC) $(CFLAGS) -o sorter *.o main.c

clean: 
	   rm -f sorter helpers.o sort.o