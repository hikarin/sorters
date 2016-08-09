FLAGS = -Wall
SOURCES = main.cpp base.cpp bubble.cpp quick.cpp comb.cpp bitonic.cpp heap.cpp
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
	$(EXECUTABLE) 50,000,000