all: $(patsubst %.cpp, %, $(wildcard *.cpp))

%: %.cpp
	g++ $< -o $@ -std=c++11 -Wall -O2 -g
