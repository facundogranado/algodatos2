CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99 -g
SOURCES = dict.c main.c dict_helpers.c string.c helpers.c
OBJECTS = $(SOURCES:.c=.o)
TARGET = dict

.PHONY: clean

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS) $(LFLAGS) $(LIBS)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJECTS) $(TARGET)
