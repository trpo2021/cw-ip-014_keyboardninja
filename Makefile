SFML := lib/SFML
SFMLLIB := lib/SFML/lib
all: $(SFMLLIB)
	g++ -c main.cpp -I. $(SFML)/include
	g++ main.o -o sfml-app -L. $(SFMLPATHLIB)-lsfml-graphics -lsfml-window -lsfml-system
$(SFMLLIB):
	git submodule update --init --recursive
	sudo apt-get install cmake-gui
	sudo apt-get install libpthread-stubs0-dev
	sudo apt-get install libgl1-mesa-dev
	sudo apt-get install libx11-dev
	sudo apt-get install libxrandr-dev
	sudo apt-get install libfreetype6-dev
	sudo apt-get install libglew1.5-dev
	sudo apt-get install libjpeg8-dev
	sudo apt-get install libsndfile1-dev
	sudo apt-get install libopenal-dev
	sudo apt-get install libudev-dev
	cmake $(SFML)/CMakeLists.txt
	make $(SFML)/Makefile
