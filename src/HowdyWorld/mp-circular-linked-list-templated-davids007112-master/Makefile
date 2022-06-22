CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./src/circular-linked-list.cc ./includes/circular-linked-list.hpp ./includes/node.hpp
	$(CXX) $(CXXFLAGS) ./src/driver.cc ./src/circular-linked-list.cc -o $@

bin/tests: ./tests/tests.cc obj/catch.o ./src/circular-linked-list.cc ./includes/circular-linked-list.hpp ./includes/node.hpp
	$(CXX) $(CXXFLAGS) ./tests/tests.cc obj/catch.o ./src/circular-linked-list.cc -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* 
