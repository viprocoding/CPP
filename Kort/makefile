# Kompilator
CC = g++

# Kompileringsinställningar
CFLAGS = -Wall -Werror -std=c++11

# Alla .cpp är källkodsfiler
SRC = $(wildcard *.cpp)

# Alla källkodsfiler måste kompileras till objektfiler
OBJ = $(SRC:.cpp=.o)

# Alla .h filer är headerfiler
HEADERS = $(wildcard *.h)

# Programmets namn
EXE = kortUtmaning.exe

$(EXE): $(OBJ)
	@echo "-----------"
	@echo "Länkar:     $@"
	@$(CC) $(CFLAGS) $(OBJ) -o $@
	@echo ""
	@echo "================="
	@echo "Exekvera program: ./$@"
	@echo "Städa:            make clean"
	@echo "================="


%.o: %.cpp
	@echo "-----------"
	@echo "Kompilerar: $^"
	@$(CC) -c $(CFLAGS) $< -o $@
    
.PHONY: clean
clean:
	rm -rf *.exe *.o
	@clear
