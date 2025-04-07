#!make -f

CXX=g++ -g
CXXFLAGS=-std=c++2a 
TESTD=runFiles/tests

TEST_SRC = $(TESTD)/*.cpp
TEST_O = $(TEST_SRC: .cpp=.o)
TSRC_O = queInt.o stack.o vertex.o graph.o priority_queue.o

Main: main.o graph.o algorithms.o vertex.o stack.o queInt.o priority_queue.o
	$(CXX) $(CXXFLAGS) graph.o main.o algorithms.o vertex.o stack.o queInt.o priority_queue.o -o Main
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

priority_queue.o: dataStructs/priority_queue.cpp dataStructs/priority_queue.hpp
	$(CXX) $(CXXFLAGS) --compile dataStructs/priority_queue.cpp -o priority_queue.o


main.o: runFiles/main.cpp basis/Graph/graph.hpp basis/algorithms.hpp
	$(CXX) $(CXXFLAGS) --compile runFiles/main.cpp -o main.o

test: $(TEST_O) $(TSRC_O)
	$(CXX) $(CXXFLAGS) $(TEST_O) $(TSRC_O) -o test
	./test

queue_test.o: queue_test.cpp dataStructs/queInt.hpp dataStructs/queInt.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@
	
stack_test.o: stack_test.cpp dataStructs/stack.hpp dataStructs/stack.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

vertex_test.o: vertex_test.cpp basis/Graph/vertex.hpp basis/Graph/vertex.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

graph_test.o: graph_test.cpp basis/Graph/graph.hpp basis/Graph/graph.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

prioq_test.o: prioq_test.cpp dataStructs/priority_queue.hpp dataStructs/priority_queue.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@

#test:
#	$(CXX) $(CXXFLAGS) runFiles/tests/*.cpp -o test.exe
#	./test.exe

%.o: %.cpp
	$(CXX) $(CXXFLAGS) --compile $< -o $@


valgrind: Main
	valgrind --leak-check=full ./Main
clean:
	rm -f *.o Main test
