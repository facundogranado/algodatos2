CFLAGS= -Wall -Werror -Wextra -pedantic -std=c99
CC=gcc
list:
		$(CC) $(CFLAGS) -g -c list.c array_helpers.c  
		$(CC) $(CFLAGS) -g -o  average *.o main.c

clean: 
	   rm -f list list.o array_helpers.o