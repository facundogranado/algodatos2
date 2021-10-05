
CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99
CC=gcc
counter:
		$(CC) $(CFLAGS) -g -c counter.c 
		$(CC) $(CFLAGS) -g -o counter *.o main.c

clean: 
	   rm -f counter counter.o