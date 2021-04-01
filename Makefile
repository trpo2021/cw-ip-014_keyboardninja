SFML := lib/SFML
SFMLLIB := lib/SFML/lib
all: $(SFMLLIB)
	g++ -c main.cpp -I. $(SFML)/include
	g++ main.o -o sfml-app -L. $(SFMLPATHLIB)-lsfml-graphics -lsfml-window -lsfml-system
$(SFMLLIB):
	git submodule update --init --recursive
	cmake $(SFML)/CMakeLists.txt
	make $(SFML)/Makefile
