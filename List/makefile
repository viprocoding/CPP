# Compiler
CC = g++

# Compiler flags
CFLAGS = -Wall -Werror -std=c++11 -ggdb

# Header files
HEADERS = Node.h

# Object files
OBJS = Test.o

# Executable name
EXE = Test.exe

# Build project
$(EXE): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Build objects
%.o: %.cpp $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

# Clean up
.PHONY: clean
clean:
	rm -rf *.exe *.o
