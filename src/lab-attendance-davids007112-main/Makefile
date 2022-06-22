CXX=clang++
CXX_FLAGS=-std=c++2a -g -O0 -Iincludes/ #-Wall -Wextra -Werror

exec: bin/exec
tests: bin/tests

bin/exec: src/main.cc includes/roster.hpp src/roster.cc includes/roster_iterator.hpp src/roster_iterator.cc includes/roster_entry.hpp
	${CXX} ${CXX_FLAGS} src/main.cc src/roster.cc src/roster_iterator.cc -o bin/exec

bin/tests: tests/tests.cc includes/roster.hpp src/roster.cc includes/roster_iterator.hpp includes/roster_iterator.cc includes/roster_entry.hpp
	${CXX} ${CXX_FLAGS} tests/tests.cc src/roster.cc src/roster_iterator.cc -o bin/tests

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -rf bin/*
