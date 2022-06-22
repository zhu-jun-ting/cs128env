CXX=clang++
CXX_FLAGS=-std=c++20 -g -O0 -Wall -Wextra -Werror -Iincludes/

.PHONY: clean tests

tests-m1: obj/test.o obj/sandwich-m1.o
	${CXX} ${CXX_FLAGS} obj/test.o obj/sandwich-m1.o -o bin/tests

tests: obj/test.o obj/sandwich.o
	${CXX} ${CXX_FLAGS} obj/test.o obj/sandwich.o -o bin/tests

my-sw-test: obj/test.o obj/my-sandwich.o
	${CXX} ${CXX_FLAGS} obj/test.o obj/my-sandwich.o -o bin/my-sw-test

obj/my-sandwich.o: includes/sandwich.hpp src/my-sandwich.cc
	${CXX} ${CXX_FLAGS} -c src/my-sandwich.cc -o obj/my-sandwich.o

obj/test.o: tests/test.cc
	${CXX} ${CXX_FLAGS} -c tests/test.cc -o obj/test.o

clean:
	rm bin/* obj/my-sandwich.o obj/test.o obj/my-sw-test.o
