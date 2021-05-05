CFLAGS := -Wall -Wextra -Werror -std=c++17
CPPFLAGS := -MMD
CXX := g++

TARGET := bin/quizrunner

SOURCES := $(wildcard src/*.cpp)
LIBSOURCES := $(wildcard src/lib/*.cpp)

LIBOBJ := $(patsubst src/lib/%.cpp, obj/src/%.o, $(LIBSOURCES))
LIB := obj/lib/quizrunnerlib.a

OBJ := $(patsubst src/%.cpp, obj/src/%.o, $(SOURCES))

TEST := $(wildcard test/*.cpp)
TESTOBJ := $(patsubst test/%.cpp, obj/test/%.o, $(TEST))
TESTTARGET := bin/testquizrunner
CTEST := thirdparty/ctest.h

SFML := thirdparty/SFML
SFMLDEP := cmake-gui libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libglew1.5-dev libjpeg8-dev libsndfile1-dev libopenal-dev libudev-dev libgl1-mesa-dev xorg-dev 
SFMLLIB := $(SFML)/lib
SFMLINCLUDE := $(SFML)/include
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET)

run: $(TARGET)
	cd bin; export LD_LIBRARY_PATH=$(SFMLLIB) && ./quizrunner

$(TARGET): $(LIB) $(OBJ) $(SFMLLIB)

	$(CXX) $(CPPFLAGS) $(CFLAGS) -o $(TARGET) $(OBJ) -L. $(LIB) -L$(SFMLLIB) $(LIBS) 

$(SFMLLIB):
	git submodule update --init --recursive
	sudo apt-get install $(SFMLDEP)
	cmake $(SFML)/CMakeLists.txt
	make -C $(SFML)

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

obj/src/%.o: src/lib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@  -I$(SFMLINCLUDE)

obj/src/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c  $< -o $@  -I$(SFMLINCLUDE) -Isrc/lib

test: $(TESTTARGET)
	./$(TESTTARGET)

$(TESTTARGET): $(TESTOBJ) $(CTEST) $(LIB)
	$(CXX) $(CPPFLAGS) $(CFLAGS)  $(TESTOBJ) -o $@ -L$(LIB) -I src/lib -Ithirdparty

obj/test/%.o: test/%.cpp $(CTEST)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c  $< -o $@ -Isrc/lib -Ithirdparty
	
clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	find . -name "quizrunner" -exec rm {} \;
	find . -name "testquizrunner" -exec rm {} \;


.PHONY: clean run test all