# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -std=c++11

# Name of the output file
OUTFILE = main

# Source files
SRCS = DynamicArray.cpp main.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

all: $(OUTFILE)

$(OUTFILE): $(OBJS)
	$(CC) $(CFLAGS) -o $(OUTFILE) $(OBJS)

.cpp.o:
	$(CC) $(CFLAGS) -c $<  -o $@

clean:
	$(RM) $(OBJS) $(OUTFILE)