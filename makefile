CC=g++
CFLAGS= -std=c++11 -Wall -pedantic -g

LDFLAGS = -L C:\MinGW\msys\1.0\lib
LIBS = -l crypto -l ssl

INCLUDE = -I C:\MinGW\msys\1.0\include

SOURCES=$(wildcard src/*.cpp)
OBJECTS=$(addprefix build/objects/, $(notdir ${SOURCES:.cpp=.o}))

EXECUTABLE=build/app/program

build/objects/%.o: src/%.cpp
	$(CC) -c -o $@ $< $(CFLAGS) $(INCLUDE) $(LDFLAGS) $(LIBS)

$(EXECUTABLE): $(OBJECTS)
	$(CC) -o $@ $^ $(CFLAGS) $(INCLUDE) $(LDFLAGS) $(LIBS)
