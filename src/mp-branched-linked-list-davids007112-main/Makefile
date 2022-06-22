CXX=clang++
INCLUDES=-Iincludes/
CXXEXTRAS=-Wall -Wextra -Werror -pedantic
CXXFLAGS=-std=c++2a -g -fstandalone-debug

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./src/branched-linked-list.cc ./includes/branched-linked-list.hpp ./includes/node.hpp
	$(CXX) $(CXXFLAGS) $(CXXEXTRAS) $(INCLUDES) ./src/driver.cc ./src/branched-linked-list.cc -o $@

bin/tests: ./tests/tests.cc obj/catch.o ./src/branched-linked-list.cc ./includes/branched-linked-list.hpp ./includes/node.hpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) ./tests/tests.cc obj/catch.o ./src/branched-linked-list.cc -o $@

obj/catch.o: tests/catch.cc
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*
