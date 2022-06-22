CXX=clang++
CXX_FLAGS=-std=c++20 -g -O0 -Wall -Wextra -Werror -Iincludes/

exec: bin/exec
tests: bin/tests

bin/exec: src/main.cc includes/solution.hpp src/solution.cc
	${CXX} ${CXX_FLAGS} src/main.cc src/solution.cc -o bin/exec

bin/tests: tests/tests.cc includes/solution.hpp src/solution.cc
	${CXX} ${CXX_FLAGS} tests/tests.cc src/solution.cc -o bin/tests

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -rf bin/*
