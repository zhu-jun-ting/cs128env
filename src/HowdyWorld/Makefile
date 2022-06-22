CXX=clang++
CXX_FLAGS=-std=c++20 -Iincludes -g -fstandalone-debug -O0 -Wall -Wextra -Werror

exec: bin/exec
tests: bin/tests

bin/exec: ./src/howdy_world.cc ./src/utilities.cc
	$(CXX) $(CXX_FLAGS) $^ -o $@

bin/tests: ./tests/tests.cc ./src/utilities.cc 
	$(CXX) $(CXX_FLAGS) $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec tests clean

clean:
	rm -f bin/*
