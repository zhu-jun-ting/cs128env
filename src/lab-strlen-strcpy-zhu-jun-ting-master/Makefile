CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -g -fstandalone-debug -Wall -Wextra -Werror -pedantic $(INCLUDES)

exec : bin/exec
	echo "You should write your own Makefile for this assignment."

bin/exec: ./src/driver.cc ./src/solution.cc
	$(CXX) $(CXXFLAGS) $^ -o $@

.DEFAULT_GOAL := exec
.PHONY: exec

clean:
	rm -fr bin/* obj/*