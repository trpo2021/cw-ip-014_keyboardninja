
SFML := lib/SFML
SFMLDEP := cmake-gui libpthread-stubs0-dev libgl1-mesa-dev libx11-dev libxrandr-dev libfreetype6-dev libglew1.5-dev libjpeg8-dev libsndfile1-dev libopenal-dev libudev-dev
SFMLLIB := lib/SFML/lib
all: $(SFMLLIB)
	g++ -c main.cpp -I. $(SFML)/include
	g++ main.o -o sfml-app -L. $(SFMLPATHLIB)-lsfml-graphics -lsfml-window -lsfml-system
$(SFMLLIB):
	git submodule update --init --recursive
	sudo apt-get install $(SFMLDEP)
	cmake $(SFML)/CMakeLists.txt
	make $(SFML)/Makefile
