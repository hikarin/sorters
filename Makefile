FLAGS = -Wall
SOURCES = main.cpp base.cpp bubble.cpp
EXECUTABLE = ./sorters
COMPILER = g++

all:
	$(COMPILER) -std=c++11 $(SOURCES) $(FLAGS) -o $(EXECUTABLE)
opt:
	$(COMPILER) -std=c++11 $(SOURCES) $(FLAGS) -o $(EXECUTABLE) -O3

clean:
	rm -f $(EXECUTABLE)

test:
	make opt
	$(EXECUTABLE) 1000