FLAGS = -Wall
SOURCES = main.cpp base.cpp bubble.cpp quick.cpp comb.cpp
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
	$(EXECUTABLE) 10
	$(EXECUTABLE) 100
	$(EXECUTABLE) 1000
	$(EXECUTABLE) 10000
	$(EXECUTABLE) 100000
	$(EXECUTABLE) 1000000