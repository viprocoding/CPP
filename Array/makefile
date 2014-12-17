# Compiler
CC = g++

# Compiler Flags
#	Wall		Use (almost) all warnings.
#	Werror		Don't compile if there are warnings.
#	std=c++11	Use C++11 Standard.
#	ggdb		Add debugging options (GDB)
CFLAGS = -Wall -Werror -std=c++11 -ggdb

# Header files
HEADERS = array.h

# Object files
OBJS = main.o

# Executable name
EXE = main.exe

# Build project
$(EXE): $(OBJS) $(HEADERS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile objects
%.o: %.cpp $(HEADERS)
	$(CC) -c $(CFLAGS) -o $@ $<

# Clean up options
.PHONY: clean
clean: 
	rm -rf *.exe *.o

