CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash

all:		main 

main:	main.o pve.o
	$(CXX) $(CXXFLAGS) main.o pve.o -o main

main.o: main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

pve.o: pve.cpp pve.h
	$(CXX) $(CXXFLAGS) -c pve.cpp

clean:
	rm -f *.o main