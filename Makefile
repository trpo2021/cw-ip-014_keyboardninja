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
SFMLLIB := $(SFML)/lib
SFMLINCLUDE := $(SFML)/include
LIBS=-lsfml-graphics -lsfml-window -lsfml-system

all: $(TARGET)

run: $(TARGET)
	cd bin; export LD_LIBRARY_PATH=../$(SFMLLIB) && ./quizrunner

$(TARGET):  $(SFMLLIB) $(LIB) $(OBJ)

	$(CXX) $(CPPFLAGS) $(CFLAGS) -o $(TARGET) $(OBJ) -L. $(LIB) -L$(SFMLLIB) $(LIBS) 

$(SFMLLIB):
	git submodule update --init --recursive
	cmake $(SFML)/CMakeLists.txt
	make -C $(SFML)

$(LIB): $(LIBOBJ)
	ar rcs $@ $^

obj/src/%.o: src/lib/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@  -I$(SFMLINCLUDE)

obj/src/%.o: src/%.cpp
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c  $< -o $@  -I$(SFMLINCLUDE) -Isrc/lib

test: $(TESTTARGET)
	cd bin; export LD_LIBRARY_PATH=../$(SFMLLIB) && ./testquizrunner

$(TESTTARGET): $(TESTOBJ) $(CTEST) $(LIB)
	$(CXX) $(CPPFLAGS) $(CFLAGS)  $(TESTOBJ) -o $@ -L. $(LIB) -I src/lib -Ithirdparty -L$(SFMLLIB) $(LIBS) 

obj/test/%.o: test/%.cpp $(CTEST) $(LIB)
	$(CXX) $(CPPFLAGS) $(CFLAGS) -c $< -o $@ -Isrc/lib -Ithirdparty -I$(SFMLINCLUDE)
	
clean:
	find . -name "*.d" -exec rm {} \;
	find . -name "*.o" -exec rm {} \;
	find . -name "*.a" -exec rm {} \;
	find . -name "quizrunner" -exec rm {} \;
	find . -name "testquizrunner" -exec rm {} \;

format:
	cd src; find . -name "*.cpp" -exec clang-format -i {} \; 
	cd src; find . -name "*.h" -exec clang-format -i {} \; 
	
.PHONY: clean run test all format