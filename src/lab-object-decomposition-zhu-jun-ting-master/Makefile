CXX=clang++
CXX_FLAGS=-std=c++20 -g -fstandalone-debug -O0 -Wall -Wextra -Werror -Iincludes/

exec: src/* includes/*
	${CXX} ${CXX_FLAGS} src/main.cc src/doctor.cc src/hospital.cc src/schedule.cc -o bin/exec

.DEFAULT_GOAL := exec
.PHONY: exec clean

clean:
	rm -rf bin/exec bin/exec.dSYM
