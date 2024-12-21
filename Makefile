CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
SRC = main.c operation.c
OBJ = $(SRC:.c=.o)
HEADERS = operation.h

TARGET = sed_simplified

all: $(TARGET)

$(TARGET): $(OBJ)
        $(CC) $(CFLAGS) -o $@ $^

%.o: %.c $(HEADERS)
        $(CC) $(CFLAGS) -c $< -o $@

clean:
        rm -f $(OBJ) $(TARGET)

test: $(TARGET)
        ./$(TARGET) input.txt -r "old_text" "new_text"
        ./$(TARGET) input.txt -d "regex"
        ./$(TARGET) input.txt -i "prefix_"
        ./$(TARGET) input.txt -b "_suffix"

.PHONY: all clean test
