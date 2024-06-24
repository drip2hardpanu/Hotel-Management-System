#
# Makefile for Hotel Management System
#

OPTFLAGS =
CXX = clang++
CXXFLAGS = $(OPTFLAGS) -gdwarf-4 -std=c++17 -Wall -Wextra -pedantic -g
LDFLAGS = $(CXXFLAGS)
LDLIBS =  
TARGETS = room-test hotel-test

all: $(TARGETS)

clean:
	rm -f $(TARGETS)
	rm -rf *.o

#room files

room-test: room.o room-test.o
	$(CXX) $(CXXFLAGS) -o room-test room-test.o room.o $(OPTFLAGS)

room-test.o: room.hpp room-test.cpp
	$(CXX) $(CXXFLAGS) -c room-test.cpp $(OPTFLAGS)

room.o: room.hpp room.cpp
	$(CXX) $(CXXFLAGS) -c room.cpp $(OPTFLAGS)
	
#hotel files
hotel-test: hotel.o hotel-test.o room.o
	$(CXX) $(CXXFLAGS) -o hotel-test hotel-test.o hotel.o room.o $(OPTFLAGS)

hotel-test.o: hotel.hpp hotel-test.cpp room.hpp
	$(CXX) $(CXXFLAGS) -c hotel-test.cpp $(OPTFLAGS)

hotel.o: hotel.hpp hotel.cpp room.hpp
	$(CXX) $(CXXFLAGS) -c hotel.cpp $(OPTFLAGS)