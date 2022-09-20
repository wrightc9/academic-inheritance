CFLAGS = -std=c++14 -Wall -g
CC = g++
SOURCEDIR = .
BUILDDIR = cmake-build-debug

EXE = school
#SOURCES = $(wildcard $(SOURCEDIR)/*.cpp)
SOURCES = $(SOURCEDIR)/main.cpp $(SOURCEDIR)/date.cpp $(SOURCEDIR)/person.cpp $(SOURCEDIR)/professor.cpp $(SOURCEDIR)/student.cpp
OBJECTS = $(patsubst $(SOURCEDIR)/%.cpp, $(BUILDDIR)/%.o, $(SOURCES))

all: dir $(BUILDDIR)/$(EXE)

dir:
	mkdir -p $(BUILDDIR)


$(BUILDDIR)/$(EXE):	$(OBJECTS)
	$(CC) $(CFLAGS) $^ -o $@

$(OBJECTS):	$(BUILDDIR)/%.o : $(SOURCEDIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(BUILDDIR)/*.o $(BUILDDIR)/$(EXE)