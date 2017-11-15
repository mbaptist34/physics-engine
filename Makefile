CC = g++
CFLAGS = -c -Wall -I/Math -I/Core
SOURCES = Math/math3.cpp Math/Transform.cpp Core/Logger.cpp Core/MMObject.cpp
OBJECTS = $(SOURCES:.cpp=.o)
EXECUTABLE = math3test

GTEST_DIR = googletest/goo
GTEST_FLAGS = -isystem $(GTEST_DIR)/include

libgtest.a:
	$(CC) $(GTEST_FLAGS) -I$(GTEST_DIR) \
		-pthread -c $(GTEST_DIR)/src/gtest-all.cc
	ar -rv libgtest.a gtest-all.o	


math3test: $(SOURCES) $(OBJECTS) libgtest.a
	$(CC) $(GTEST_FLAGS) -pthread Math/math3test.cpp libgtest.a Math/math3.o -o math3test

transformTest: $(SOURCES) $(OBJECTS) libgtest.a Math/transformTest.cpp
	$(CC) $(GTEST_FLAGS) -pthread Math/transformTest.cpp libgtest.a $(OBJECTS) -o transformTest

clean:
	touch dummy.o
	rm *.o
	touch  Math/dummy.o
	rm Math/*.o
	touch Physics/dummy.o
	rm Physics/*.o
	touch Core/dummy.o
	rm Core/*.o
	touch Game/dummy.o
	rm Game/*.o
	touch math3test
	rm math3test	

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
