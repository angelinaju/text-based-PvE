CXX=		g++
CXXFLAGS=	-Wall -g

TARGET = game

SRCS = main.cpp pve.cpp
OBJS = main.o pve.o  

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

main.o: main.cpp pve.h
	$(CXX) $(CXXFLAGS) -c main.cpp

pve.o: pve.cpp pve.h
	$(CXX) $(CXXFLAGS) -c pve.cpp

clean:
	rm -f $(OBJS) $(TARGET)
