#!make -f

CXX=g++
CXXFLAGS=-std=c++2a 

all: Main
	./Main

Main: main.o graph.o algorithms.o vertex.o stack.o queInt.o
	$(CXX) $(CXXFLAGS) graph.o main.o algorithms.o vertex.o stack.o queInt.o -o Main

graph.o: graph.cpp graph.hpp vertex.hpp
	$(CXX) $(CXXFLAGS) --compile graph.cpp -o graph.o

algorithms.o: algorithms.cpp algorithms.hpp graph.hpp queInt.hpp stack.hpp
	$(CXX) $(CXXFLAGS) --compile algorithms.cpp -o algorithms.o

stack.o: stack.cpp stack.hpp
	$(CXX) $(CXXFLAGS) --compile stack.cpp -o stack.o

vertex.o: vertex.cpp vertex.hpp
	$(CXX) $(CXXFLAGS) --compile vertex.cpp -o vertex.o

queInt.o: queInt.cpp queInt.hpp
	$(CXX) $(CXXFLAGS) --compile queInt.cpp -o queInt.o

main.o: main.cpp graph.hpp algorithms.hpp
	$(CXX) $(CXXFLAGS) --compile main.cpp -o main.o

clean:
	rm -f *.o Main