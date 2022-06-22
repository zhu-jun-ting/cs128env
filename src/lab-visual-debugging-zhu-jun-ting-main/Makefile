CXX = clang++
CXX_FLAGS = -std=c++20  -g -O0 -Wall -Wextra -Iincludes  #-Werror

.PHONY: tests clean

exec: main.o restaurant.o
	${CXX} ${CXX_FLAGS} -lc++abi bin/main.o bin/restaurant.o -o bin/exec -g -fstandalone-debug

main.o: src/main.cc restaurant.o includes/supplier.hpp includes/customer.hpp
	${CXX} ${CXX_FLAGS} -c src/main.cc -g -o bin/main.o

tests: tests.o restaurant.o
	${CXX} ${CXX_FLAGS} -lc++abi bin/tests.o bin/restaurant.o -o bin/tests

tests.o: tests/catch.hpp tests/tests.cc restaurant.o includes/supplier.hpp includes/customer.hpp
	${CXX} ${CXX_FLAGS} -c tests/tests.cc -o bin/tests.o

restaurant.o: includes/restaurant.hpp src/restaurant.cc includes/supplier.hpp includes/customer.hpp
	${CXX} ${CXX_FLAGS} -c src/restaurant.cc -o bin/restaurant.o

clean:
	-rm -f *.o bin/main bin/tests bin/exec bin/main.o bin/restaurant.o bin/tests.o
