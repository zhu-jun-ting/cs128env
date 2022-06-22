CXX=clang++
CXX_FLAGS=-std=c++20 -g -O0 -Wall -Wextra -Werror -Iincludes/

exec: bin/exec
tests: bin/tests

bin/exec: exec.o obj/zoo.o
	${CXX} ${CXX_FLAGS} obj/exec.o obj/zoo.o -o bin/exec

exec.o: src/main.cc zoo.o includes/animal.hpp
	${CXX} ${CXX_FLAGS} -c src/main.cc -o obj/exec.o

bin/tests: tests.o zoo.o
	${CXX} ${CXX_FLAGS} obj/tests.o obj/zoo.o -o bin/tests

tests.o: tests/catch.hpp tests/test.cc includes/zoo.hpp includes/animal.hpp
	${CXX} ${CXX_FLAGS} -c tests/test.cc -o obj/tests.o

zoo.o: includes/zoo.hpp src/zoo.cc includes/animal.hpp
	${CXX} ${CXX_FLAGS} -c src/zoo.cc -o obj/zoo.o

.PHONY: exec tests clean

clean:
	rm -f bin/* obj/*

