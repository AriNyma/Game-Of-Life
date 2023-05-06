IDIR=../include

# constants
CC = gcc
CFLAGS = -Wall -ansi -pedantic

# source files
SRCS = game_of_life.c count_neighbours.c initialize_table.c current.c future.c read_file.c

_DEPS = hellomake.h
DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

# object files
OBJS = $(SRCS:.c=.o)

# executable name
TARGET = game.exe

# Rule to compile each C-file separately
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Rule to compile the whole program
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

# Set phony targets
.PHONY: clean 

# Rule to clean all files except C-files and Makefile
clean:
	del -f $(OBJS) $(TARGET) *.s

# Rule to compile all files to assembler
asm: $(SRCS)
	$(CC) $(CFLAGS) -S $^

# Set phony targets
.PHONY: clean asm
