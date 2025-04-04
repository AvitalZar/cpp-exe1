#!make -f

CXX=g++
CXXFLAGS=-std=c++2a 
TESTD=runFiles/tests

TEST_SRC = $(TESTD)/*.cpp
TEST_O = $(TEST_SRC: .cpp=.o)

all: Main test

Main: main.o graph.o algorithms.o vertex.o stack.o queInt.o
	$(CXX) $(CXXFLAGS) graph.o main.o algorithms.o vertex.o stack.o queInt.o -o Main
	./Main


graph.o: basis/Graph/graph.cpp basis/Graph/graph.hpp basis/Graph/vertex.hpp
	$(CXX) $(CXXFLAGS) --compile basis/Graph/graph.cpp -o graph.o

algorithms.o: basis/algorithms.cpp basis/algorithms.hpp basis/Graph/graph.hpp dataStructs/queInt.hpp dataStructs/stack.hpp
	$(CXX) $(CXXFLAGS) --compile basis/algorithms.cpp -o algorithms.o

stack.o: dataStructs/stack.cpp dataStructs/stack.hpp
	$(CXX) $(CXXFLAGS) --compile dataStructs/stack.cpp -o stack.o

vertex.o: basis/Graph/vertex.cpp basis/Graph/vertex.hpp
	$(CXX) $(CXXFLAGS) --compile basis/Graph/vertex.cpp -o vertex.o

queInt.o: dataStructs/queInt.cpp dataStructs/queInt.hpp
	$(CXX) $(CXXFLAGS) --compile dataStructs/queInt.cpp -o queInt.o

main.o: runFiles/main.cpp basis/Graph/graph.hpp basis/algorithms.hpp
	$(CXX) $(CXXFLAGS) --compile runFiles/main.cpp -o main.o

test: $(TEST_O) queInt.o
	$(CXX) $(CXXFLAGS) $(TEST_O) queInt.o -o test
	./test

queue.o: queue.cpp dataStructs/queInt.hpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

#test:
#	$(CXX) $(CXXFLAGS) runFiles/tests/*.cpp -o test.exe
#	./test.exe

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

clean:
	rm -f *.o Main test
