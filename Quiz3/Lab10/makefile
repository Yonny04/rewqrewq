CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SOURCES=BST.cpp UnableToInsertException.cpp BSTTestDriver.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=bst

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.o $(EXECUTABLE)
