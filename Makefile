CC = g++
CFLAGS = -Wall -Wextra -c
LFLAGS = -Wall

GTEST_DIR = ~/Programming/googletest/googletest
GTEST_FLAGS = -isystem $(GTEST_DIR)/include


math3Test: math3.o libgtest.a math3test.cpp
	$(CC) $(GTEST_FLAGS) -pthread math3test.cpp libgtest.a math3.o\
		-o math3test

libgtest.a:
	$(CC) $(GTEST_FLAGS) -I$(GTEST_DIR) \
		-pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o	

math3.o: math3.cpp math3.hpp AlmostEquals.h
	$(CC) $(CFLAGS) math3.cpp

rm:
	rm *.o
	rm math3Test

